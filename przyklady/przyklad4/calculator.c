#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"


void print_menu(PluginManager * manager){
    printf("\n\n-------------------------------\n");
    printf("|                             |\n");
    printf("|           WELCOME           |\n");
    printf("|                             |\n");
    printf("-------------------------------\n\n");
    printf("        Choose operation:\n");
    printf("> e - exit app\n");

    apply_menu_hooks(manager);

    char request = getchar();
    handle_response(manager, request);
}


void handle_response(PluginManager * manager, char request){
    if (request == 'e'){
        puts("Bye...");
        exit(-1);
    }

    int req = apply_response_hooks(manager, request);
    if(req == -1){
        puts("Wrong request");
    }

}
