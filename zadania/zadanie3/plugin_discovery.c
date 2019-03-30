#include "plugin_discovery.h"

#include <dirent.h>
#include <dlfcn.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

//single plugin with it's discovery state
typedef struct PluginHandleList_t {
    void * handle;
    struct PluginHandleList_t * next;
} PluginHandleList;

//handle list of plugins and their states
typedef struct PluginDiscoveryState_t {
    PluginHandleList * handle_list;
} PluginDiscoveryState;

//typedef for plugins init functions
typedef int (* PluginInitFun) (PluginManager * );

static char * get_plugin_name(char* filename) {
    //search for filenames (not directories)
    char* last_slash = strrchr(filename, '/');
    //check where the name starts 
    //- from the last slash (in case theres directory before name) or from beggining (no directory before name)
    char* name_start = last_slash ? last_slash + 1 : filename;
    //search for last dot - file extension
    char* last_dot = strrchr(filename, '.');

    //files with .so
    if (!last_dot || strcmp(last_dot, ".so"))
        return NULL;

    //get the name
    int len = last_dot - name_start;
    char * name = malloc ( len + 1);
    strncpy(name, name_start, len);
    name[len] = '\0';

    return name;
}

static char * get_path(char * dirname, char * filename){
    char * path = malloc (strlen(dirname) + strlen(filename) + 2);
    strcpy(path, dirname);
    strcat(path, "/");
    strcat(path, filename);
    strcat(path, "\0");
    return path;
}

//try to load plugin
static void * load_plugin(char * name, char * fullpath, PluginManager * manager) {
    //get the path to lib
    char * path = malloc (strlen(fullpath) + 3);
    //current directory prefix
    strcpy(path, "./");
    strcat(path, fullpath); 

    //open plugin
    void * handle = dlopen(path, RTLD_NOW);
    free(path);

    if (!handle) {
        printf("Error loading DSO: %s\n", dlerror());
        return NULL;
    }

    //get the name of init function
    char * init_fun_name = malloc(strlen(name) + 6);
    strcpy(init_fun_name, "init_");
    strcat(init_fun_name, name);

    //dlsym returns void * that we need to cast to function pointer
    PluginInitFun init_fun = (PluginInitFun) (intptr_t) dlsym(handle, init_fun_name);
    free(init_fun_name);

    if (!init_fun) {
        printf("Error loading init function: %s\n", dlerror());
        dlclose(handle);
        return NULL;
    }

    int r = init_fun(manager);
    if (r < 0) {
        printf("Error: Plugin init function returned %d\n", r);
        dlclose(handle);
        return NULL;
    }

    printf("Loaded plugin from: '%s'\n", fullpath);
    return handle;
}

void * discover_plugins(char * dirname, PluginManager * manager){
    DIR* dir = opendir(dirname);
    if (!dir) {
        printf("Unable to open path '%s'", dirname);
        return NULL;
    }

    //init discovered plugins list
    PluginDiscoveryState * plugins_state = malloc(sizeof(*plugins_state));
    plugins_state->handle_list = NULL;

    //try to load plugins from plugin directory
    struct dirent * d;
    while ((d = readdir(dir))) {
        char * name = get_plugin_name(d->d_name);
        if (!name) continue;

        //get the path to plugin
        char * path = get_path(dirname, d->d_name);
        
        //load plugin
        void * handle = load_plugin(name, path, manager);
        
        //push plugin to list
        if(handle){
            PluginHandleList * new_node = malloc (sizeof(PluginHandleList));
            new_node->handle = handle;
            new_node->next = plugins_state->handle_list;
            plugins_state->handle_list = new_node;
        }

        if (name) free(name);
        free(path);
    }
    closedir(dir);

    // Return a state if plugins were found.
    if (plugins_state->handle_list)
        return (void *) plugins_state;
    else {
        free(plugins_state);
        return NULL;
    }
}

void cleanup_plugins(void* vpds) {
    PluginDiscoveryState* pds = (PluginDiscoveryState*)vpds;
    PluginHandleList* node = pds->handle_list;
    while (node) {
        PluginHandleList* next = node->next;
        dlclose(node->handle);
        free(node);
        node = next;
    }
    free(pds);
}