#pragma once

#include "plugin_manager.h"

//printing menu with available actions
void print_menu (PluginManager * manager);

//handle action connected to request - returns 0 when should exit
int handle_response(PluginManager * manager, char request);

//main app loop - returns handle_response
int app(PluginManager * manager);

//opening screen
void start(PluginManager * manager);