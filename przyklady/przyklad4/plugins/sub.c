//plugin with subtraction

#include "plugin_manager.h"
#include <stdio.h>

//function that implements plugin functionality
void sub_contents_hook();

//to print plugin option in menu
void sub_menu_hook();

//function that initialize plugin
int init_sub(PluginManager * manager) {
    Register_menu_hook(manager, sub_menu_hook);
    return 1;
}

void sub_menu_hook(){
    puts("> s - subtract two numbers");
}

void subtraction_contents_hook(){
    double a, b;
    puts("Enter numbers");
    scanf("%lf", &a);
    scanf("%lf", &b);

    printf ("= %lf", a-b);
}