#pragma once

#include "plugin_manager.h"

//printing menu with available actions
void print_menu( PluginManager * manager );

//handle action connected to request
void handle_response(char request);