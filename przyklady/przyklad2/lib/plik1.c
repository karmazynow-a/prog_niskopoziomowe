#include "plik1.h"

void shout (char * word){
    int i;
    for (i=0; word[i] != '\0'; ++i){
        if (word[i] > 96)
            printf ("%c", word[i] - 32);
        else 
            printf ("%c", word[i]);
    }
    puts("");
    //puts("zmiana!");
}
