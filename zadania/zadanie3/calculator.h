#pragma once

#include "plugin_manager.h"

//printing menu with available actions
void print_menu (PluginManager * manager);

//handle action connected to request
void handle_response(PluginManager * manager, char request);

//main app loop
void app(PluginManager * manager);

//opening screen
void start(PluginManager * manager);