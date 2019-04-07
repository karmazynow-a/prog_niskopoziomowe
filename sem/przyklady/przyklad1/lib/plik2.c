#include "plik2.h"

void whisper (char * word){
    int i;
    for (i=0; word[i] != '\0'; ++i){
        if (word[i] > 96)
            printf ("%c", word[i]);
        else 
            printf ("%c", word[i] + 32);
    }
    puts("");
    //puts("Zmiana");
}
