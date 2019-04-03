//plugin with subtraction

#include "plugin_manager.h"
#include <stdio.h>

// plugin operation
void sub_operation_hook();

//to print plugin option in menu
void sub_menu_hook();

//function that initialize plugin
int init_sub(PluginManager * manager) {
    register_menu_hook(manager, sub_menu_hook);
    register_response_hook(manager, sub_operation_hook, 's');
    return 1;
}

void sub_menu_hook(){
    puts("> s - subtract two numbers");
}

void sub_operation_hook(){
    double a, b;
    puts("Enter numbers");
    scanf("%lf", &a);
    scanf("%lf", &b);

    printf ("= %.3lf", a-b);
}