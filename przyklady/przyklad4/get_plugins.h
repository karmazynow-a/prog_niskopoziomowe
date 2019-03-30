//plugin discovery system

#pragma once

//get name of library
char * get_plugin_name(char* filename) {
    //search for filenames (not directories)
    char* last_slash = strrchr(filename, '/');
    //check where the name starts 
    //- from the last slash (in case theres directory before name) or from beggining (no directory before name)
    char* name_start = last_slash ? last_slash + 1 : filename;
    //search for last dot - file extension
    char* last_dot = strrchr(filename, '.');

    //files with .so
    if (!last_dot || strcmp(last_dot, ".so"))
        return NULL;

    //get the name
    int len = last_dot - name_start;
    char * name = malloc ( len + 1);
    strncpy(name, name_start, len);
    name[len] = '\0';

    return name;
}


char * get_path(char * dirname, char * filename){
    //budujemy ścieżkę do pluginu ./folder/nazwa_pliku
    char * path = malloc (strlen(dirname) + strlen(filename) + 3);

    strcpy(path, "./");
    strcat(path, dirname);
    strcat(path, "/");
    strcat(path, filename);
    strcat(path, "\0");

    return path;
}