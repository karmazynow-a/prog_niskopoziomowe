
#include <stdio.h>

void shout(){
    puts("GREETINGS FROM PLUGIN!");
}

void process (){
    puts("Plugin fun1");

    //funkcja stanowiąca interfejs może wywoływać inny funkcje
    shout();
}
