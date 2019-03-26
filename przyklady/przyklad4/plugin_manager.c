#include "plugin_manager.h"
#include <stdlib.h>

#include <stdio.h>

PluginManager * pluginManager_new() {
    PluginManager * new_manager = malloc( sizeof(PluginManager) );
    new_manager -> menu_hook_list = NULL;
    new_manager -> response_hook_list = NULL;
    return new_manager;
}

void pluginManager_free(PluginManager * manager) {
    //free menu list
    PluginMenuHookList * tmp = manager->menu_hook_list;

    while (tmp) {
        PluginMenuHookList * next = tmp->next;
        free(tmp);
        tmp = next;
    }

    free(manager);
}

void register_menu_hook(PluginManager * manager, PluginMenuHook hook){
    PluginMenuHookList * new_node = malloc (sizeof(PluginMenuHookList));
    new_node -> hook = hook;
    new_node -> next = manager->menu_hook_list;
    manager->menu_hook_list = new_node;
}

void register_response_hook(PluginManager * manager, PluginResponseHook hook, char trigger){
    PluginResponseHookList * new_node = malloc (sizeof(PluginResponseHookList));
    new_node -> plugin_trigger = trigger;
    new_node -> hook = hook;
    new_node -> next = manager->response_hook_list;
    manager->response_hook_list = new_node;
}

void apply_menu_hooks(PluginManager * manager){
    PluginMenuHookList * tmp = manager->menu_hook_list;
    if (!tmp) return;

    while (tmp){
        tmp->hook();
        tmp = tmp->next;
    }
}

int apply_response_hooks(PluginManager * manager, char request){
    PluginResponseHookList * tmp = manager->response_hook_list;

    if (!tmp) return -1;

    while (tmp){
        if (tmp->plugin_trigger == request){
            tmp->hook();
            break;
        }

        tmp = tmp->next;
    }
    //we went through list 'till the end
    if (!tmp) return -1;
    //tmp is not null - we broke the loop
    else return 0;
}