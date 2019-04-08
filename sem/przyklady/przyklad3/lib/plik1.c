#include "plik1.h"
#include <string.h>

void jestem_void (int i){
    printf("Mam integer: %d\n", i);
}

int jestem_int (void){
    puts("Nie mam nic, więc zwracam zero");
    return 0;
}

float jestem_float (float f, float e){
    printf("Mam float: %f oraz %f i oddaje jedną!\n", f, e);
    return f;
}

char * jestem_tablica (int * k){
    printf("Mam wskaźnik: %ls, więc ci coś powiem\n", k);
    return "Hejka";
}

int jestem_niewykorzystany (void){
    puts("Nie mam nic i nikt mnie nie używa :(");
    return 0;
}