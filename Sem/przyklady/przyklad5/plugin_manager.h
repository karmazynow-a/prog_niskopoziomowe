//plugin manager interface
#pragma once

//menu hook
typedef void (*PluginMenuHook)();

//response operation hook
typedef void (*PluginResponseHook)();

//hooks of menu stored by linked list
typedef struct PluginMenuHookList_t {
    PluginMenuHook hook;
    struct PluginMenuHookList_t * next;
} PluginMenuHookList;

//hooks of response stored by linked list
typedef struct PluginResponseHookList_t {
    char plugin_trigger;
    PluginResponseHook hook;
    struct PluginResponseHookList_t * next;
} PluginResponseHookList;

//plugin manager with two lists of hooks
typedef struct PluginManager_t {
    PluginMenuHookList * menu_hook_list;
    PluginResponseHookList * response_hook_list;
} PluginManager;

//create new PluginManager
PluginManager* pluginManager_new();

//destroy PluginManager
void pluginManager_free(PluginManager * manager);

//add new menu hook to the list
void register_menu_hook(PluginManager * manager, PluginMenuHook hook);

//apply menu list
void apply_menu_hooks(PluginManager* pm);

//add new response hook to the list
void register_response_hook(PluginManager * manager, PluginResponseHook hook, char trigger);

//apply response list
//if there's no suitable response returns -1
int apply_response_hooks(PluginManager* pm, char request);