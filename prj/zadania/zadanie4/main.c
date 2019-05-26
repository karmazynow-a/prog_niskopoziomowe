//korzystając z programu dwarfdump odczytaj funkcje/symbole zawartych w bibliotece
//i uzupełnij kod w wyznaczonych miejscach aby wyeliminować warningi 
//-Wimplicit-function-declaration, a następnie doprowadzić do kompilacji

//interesujące nas fragmenty dwarfdump:
//DW_AT_name - nazwa
//DW_TAG_formal_parameter - argumenty funkcji
//DW_AT_type - typ zwracany
//  typ zwracany przekierowuje nas do innego DIE
//  w którym znajdziemy poszukiwany typ

//nazwy funkcji zdefiniowanych w tym pliku obiektowym otrzymamy przez komendę:
//nm --defined-only ./lib/plik1.o

#include <stdio.h>
#include <stdlib.h>

int main(void){

    fun1 ( /*UZUPEŁNIJ*/ );
    fun2 ( /*UZUPEŁNIJ*/ ) ;
    fun3 ( /*UZUPEŁNIJ*/ ) ;
    fun5 ( /*UZUEPŁNIJ NAZWE FUNKCJI*/ (1));
    
    return 0;
}
