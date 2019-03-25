#include "plugin_manager.h"
#include <stdlib.h>

// The hooks are contained in simple singly-linked lists
typedef struct PluginMenuHookList_t {
    PluginMenuHook hook;
    struct PluginMenuHookList_t* next;
} PluginMenuHookList;

struct PluginManager_t {
    PluginMenuHookList * menu_hook_list;
};

PluginManager* PluginManager_new() {
    PluginManager * manager = malloc(sizeof(*manager));
    manager -> menu_hook_list = NULL;
    return manager;
}

void PluginManager_free(PluginManager * manager) {
    //free menu list
    PluginMenuHookList * tmp = manager->menu_hook_list;

    while (tmp) {
        PluginMenuHookList * next = tmp->next;
        free(tmp);
        tmp = next;
    }

    free(manager);
}

void Register_menu_hook(PluginManager * manager, PluginMenuHook hook){
    PluginMenuHookList * new_node = malloc (sizeof(PluginMenuHookList));
    new_node -> hook = hook;
    new_node -> next = manager->menu_hook_list;
    manager->menu_hook_list = new_node;
}

void Apply_menu_hooks(PluginManager* manager){
    PluginMenuHookList * tmp = manager->menu_hook_list;

    if (!tmp) return NULL;
    while (tmp){
        tmp->hook();
        tmp = tmp->next;
    }
}