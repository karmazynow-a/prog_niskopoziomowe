//main rogramm for calculator app
//with plugin system
//inspired by https://eli.thegreenplace.net/2012/08/24/plugins-in-c

#include "calculator.h"
#include "plugin_discovery.h"
#include "plugin_manager.h"

int main(int argc, const char* argv[]) {
    //init plugins
    PluginManager * manager = pluginManager_new();
    void* pdstate = discover_plugins("plugins", manager);  

    //main app loop
    start(manager);
    while (0==0){
        app(manager);
    }

    return 0;
}