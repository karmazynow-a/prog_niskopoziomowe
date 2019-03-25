//plugin manager interface

#pragma once

// Role hook. Will be called with: the role contents, DB and Post objects.
typedef void (*PluginMenuHook)();

typedef struct PluginManager_t PluginManager;

// Create a new plugin manager.
PluginManager* PluginManager_new();

// Free the memory of a plugin manager.
void PluginManager_free(PluginManager * manager);

//add new menu hook to the list
void Register_menu_hook(PluginManager * manager, PluginMenuHook hook);

//apply menu list
void Apply_menu_hooks(PluginManager* pm);