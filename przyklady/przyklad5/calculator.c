#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"


void start(PluginManager * manager){
    printf("\n\n-------------------------------\n");
    printf("|                             |\n");
    printf("|           WELCOME           |\n");
    printf("|                             |\n");
    printf("-------------------------------\n\n");
    print_menu(manager);

    puts("\n-------------------------------\n");
    puts("Your request:");
}

int app(PluginManager * manager){
    char request = getchar();
    
    if(request != 10)
        return handle_response(manager, request);
    return 1;
}

void print_menu(PluginManager * manager){
    printf(" Available operation:\n");

    //print menu options from loaded plugins
    apply_menu_hooks(manager);

    printf("> m - show menu\n");
    printf("> e - exit app\n");
}

int handle_response(PluginManager * manager, char request){
    int req = apply_response_hooks(manager, request);

    if (request == 'e'){
        puts("Bye...");
        return 0;
        //exit(-1);
    } 
    else if (request == 'm'){
        print_menu(manager);
    }   
    else if(req == -1){
        puts("Wrong request");
    } 

    puts("");
    puts("\n-------------------------------\n");
    puts("Your request:");
    return 1;
}
