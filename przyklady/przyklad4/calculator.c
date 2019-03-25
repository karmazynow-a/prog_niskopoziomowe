#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"


void print_menu( PluginManager * manager ){
    printf("\n\n-------------------------------\n");
    printf("|                             |\n");
    printf("|           WELCOME           |\n");
    printf("|                             |\n");
    printf("-------------------------------\n\n");
    printf("        Choose operation:\n");
    printf("> e - exit app\n");

    Apply_menu_hooks(manager);

    char request = getchar();
    handle_response(request);
}


void handle_response(char request){
    if (request == 'e'){
        puts("Bye...");
        exit(-1);
    }
    else {
        puts("Wrong request");
    }

}
