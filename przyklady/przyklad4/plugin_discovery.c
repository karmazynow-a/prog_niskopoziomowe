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
    //search for folenames not directories
    char* last_slash = strrchr(filename, '/');
    //check where the name starts - from the last / or from beggining
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

//try to load plugin
static void * load_plugin(char * name, char * fullpath, PluginManager * manager) {
    //get the path to lib
    char * path = malloc (strlen(fullpath) + 3);
    path[0] = '.';
    path[1] = '/'; 
    strcat(path, fullpath); 

    //open plugin
    void * libhandle = dlopen(path, RTLD_NOW);
    free(path);

    if (!libhandle) {
        printf("Error loading DSO: %s\n", dlerror());
        return NULL;
    }

    //get the name of init function
    char * init_fun_name = malloc(strlen(name) + 6);
    char tmp [5] = "init_";
    strcpy(init_fun_name, tmp);
    strcat(init_fun_name, name);

    //dlsym returns void * that we need to cast to function pointer
    PluginInitFun init_fun = (PluginInitFun) (intptr_t) dlsym(libhandle, init_fun_name);
    free(init_fun_name);

    if (!init_fun) {
        printf("Error loading init function: %s\n", dlerror());
        dlclose(libhandle);
        return NULL;
    }

    int r = init_fun(manager);
    if (r < 0) {
        printf("Error: Plugin init function returned %d\n", r);
        dlclose(libhandle);
        return NULL;
    }

    printf("Loaded plugin from: '%s'\n", fullpath);
    return libhandle;
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
        char * path = malloc (strlen(dirname) + strlen(d->d_name) + 2);
        strcpy(path, dirname);
        path[strlen(dirname)] = '/';
        strncat(path, d->d_name, strlen(d->d_name));
        
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