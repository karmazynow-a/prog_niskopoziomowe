//plugin with addition

#include "plugin_manager.h"
#include <stdio.h>

//function that implements plugin functionality
void add_contents_hook();

//to print plugin option in menu
void add_menu_hook();

//function that initialize plugin
int init_add(PluginManager * manager) {
    Register_menu_hook(manager, add_menu_hook);
    return 1;
}

void add_menu_hook(){
    puts("> a - add two numbers");
}

void add_operation_hook(){
    double a, b;
    puts("Enter numbers");
    scanf("%lf", &a);
    scanf("%lf", &b);

    printf ("= %lf", a-b);
}