//korzystając z programu dwarfdump odczytaj funkcje/symbole zawartych w bibliotece
//i uzupełnij kod w wyznaczonych miejscach aby doprowadzić do kompilacji
//interesujące nas fragmenty:
//DW_AT_name - nazwa
//DW_TAG_formal_parameter - argumenty funkcji
//DW_AT_type - typ zwracany
//  typ zwracany przekierowuje nas do innego DIE
//  w którym znajdziemy poszukiwany typ

//nazwy funkcji zdefiniowanych w tym pliku obiektowym otrzymamy przez komendę:
//nm --defined-only ./lib/liblib.a

//należy również wyeliminować warningi -Wimplicit-function-declaration

#include <stdio.h>
#include <stdlib.h>



int main(void){

    fun1 ( /*UZUPEŁNIJ*/ );
    fun2 (/*UZUPEŁNIJ*/ 5.6) ;
    fun3 ( /*UZUPEŁNIJ*/ "tak") ;
    fun5 ( /*UZUEPŁNIJ NAZWE FUNKCJI*/ fun6(1));
    
    return 0;
}