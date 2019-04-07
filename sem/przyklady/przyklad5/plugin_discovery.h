#pragma once

#include "plugin_manager.h"

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

// Given a directory name, looks for plugins in this directory. pm
// is passed to plugins for registration.
// Returns an opaque state object that has to be passed to the cleanup function
// later. If no plugins are found, returns NULL.
//
void * discover_plugins(char * dirname, PluginManager * manager);

// Cleans up the plugins's resources. Must be called to release plugins in
// order to avoid resource leaks. Accepts the opaque object returned from
// discover_plugins.
//
void cleanup_plugins(void*);