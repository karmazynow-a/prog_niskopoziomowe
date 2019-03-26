//plugin with addition

#include "plugin_manager.h"
#include <stdio.h>

//to print plugin option in menu
void add_menu_hook();

//response on trigger
void add_operation_hook();

//function that initialize plugin
int init_add(PluginManager * manager) {
    register_menu_hook(manager, add_menu_hook);
    register_response_hook(manager, add_operation_hook, 'a');
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

    printf ("= %.3lf", a-b);
}