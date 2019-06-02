//Zadaniem jest napisanie prostego systemu wtyczek
//Zakładamy że nazwy wtyczek podane są w tablicy plugins w main, i znajdują się w folderze o tej samej nazwie
//Program powinien przyjmować od użytkownika ciąg znaków (jako argument wywołania lub 
//przez sprintf)
//Wtyczki powinny być dwie i realizować dwa działania na owym stringu i wypisywać je na ekran
//np zamieniać wszystkie litery na wielkie, mieszać kolejność liter, wypisywać tylko 
//samogłoski, wypisywać wyraz od tyłu etc
//Należy pamiętać o uzupełnieniu makefile!

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, const char* argv[]) {
    if ( argc < 2 ){
        puts ("Wymagany jest argument");
        exit(-1);
    }

    void *handle;
    typedef char * (*process_plugin) (char *);
    process_plugin process;
    char * plugin_dir = "plugins";

    char * plugins [2];
    plugins [0] = "./plugins/plugin1.so";
    plugins [1] = "./plugins/plugin2.so";

    int i;
    for (i = 0; i < 2; ++i){
        handle = dlopen(plugins[i], RTLD_NOW);
        process = dlsym(handle, "process_string");
        
        puts(process(argv[1]));
        dlclose(handle);
    }

    return 0;
}