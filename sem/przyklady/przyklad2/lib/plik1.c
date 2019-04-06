#include "plik1.h"

void jestem_void (int i){
    printf("Mam integer: %d\n", i);
}

int jestem_int (void){
    puts("Nie mam nic, więc zwracam zero");
    return 0;
}

float jestem_float (float f){
    printf("Mam float: %f i oddaje!\n", f);
    return f;
}

char * jestem_tablica (int * k){
    printf("Mam wskaźnik: %ls, więc ci coś powiem\n", k);
    char * slowo = malloc (6);
    slowo = "Hejka";
    return slowo;
}

int jestem_niewykorzystany (void){
    puts("Nie mam nic i nikt mnie nie używa :(");
    return 0;
}