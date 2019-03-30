//Celem zadania jest napisanie wtyczki do programu kalkulatora 
//prezentowanego na zajęciach.
//Jej budowa musi być zgodna z zaprojektowanym interfejsem
//czyli posiadać funkcje init_, która rejestruje odpowiednie funkcję
//do wypisywania opcji pluginu w menu oraz do wykonywania działania
//Wtyczka powinna dodać obsługę mnożenia/dzielenia/potęgowania
//należy pamiętać o uwzględnieniu nowej wtyczki w makefilu!

#include "calculator.h"
#include "plugin_discovery.h"
#include "plugin_manager.h"

int main(int argc, const char* argv[]) {
    //init plugins
    PluginManager * manager = pluginManager_new();
    discover_plugins("plugins", manager);  

    //main app loop
    start(manager);
    while (0==0){
        app(manager);
    }

    return 0;
}