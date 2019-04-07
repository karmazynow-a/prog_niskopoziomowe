//przykład demonstrujący użycie program dwarfdump do odczytania funkcji/symboli
//zawartych w bibliotece
//dostęp do nich uzyskuje się komendą dwarfdump:
//DW_AT_name - nazwa
//DW_TAG_formal_parameter - argumenty funkcji
//DW_AT_type - typ zwracany
//  typ zwracany przekierowuje nas do innego DIE
//  w którym znajdziemy poszukiwany typ

//nazwy funkcji zdefiniowanych w tym pliku obiektowym otrzymamy przez komendę:
//nm --defined-only ./lib/plik1.o


#include <stdio.h>
#include <stdlib.h>

#include "lib/plik1.h"

int main(void){
    int i = 8;
    jestem_void(i);
    jestem_int();
    jestem_float(3.16, 4.08);

    char * s = jestem_tablica (&i);
    puts(s);
    free(s);
    
    return 0;
}