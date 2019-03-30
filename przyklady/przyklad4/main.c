/* Przykład demonstrujący prosty system pluginów
*   Pluginy znajdują się w folderze "plugins"
*   Interfejs składa się z funkcji void process()
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <dlfcn.h>

#include "get_plugins.h"

int main(int argc, const char* argv[]) {
    //zmienna przechowująca otwarty plugin
    void *handle;
    //wskaźnik na funkcje z pluginów
    typedef void (*process_plugin) ();
    process_plugin process;
    //nazwa folderu z pluginami
    char * plugin_dir = "plugins";

    //folder z pluginami
    DIR* dir = opendir(plugin_dir);
    struct dirent * file;

    while (file = readdir(dir)){
        //sprawdzamy czy plik w folderze jest pluginem (biblioteką dynamiczną)
        char * name = get_plugin_name (file->d_name);
        if (!name) continue;

        //budujemy ścieżkę do pluginu ./folder/nazwa_pliku
        char * path = get_path(plugin_dir, file->d_name);

        handle = dlopen(path, RTLD_NOW);

        process = dlsym(handle, "process");

        process();

        dlclose(handle);
        free(path);
    }


    return 0;
}