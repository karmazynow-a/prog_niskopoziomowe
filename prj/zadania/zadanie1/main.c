//Zadanie polega na dopisaniu brakującej biblioteki, a potem stworzenie ich,
//aby można było skompilować program za pomocą komendy
//gcc main.c -L./lib -lfun2 -lfun1
//bez żadnych errorów/warningów
//Trzeba w funkcji fun2 wykorzystać fun1
//plików main.c oraz fun1.c nie można zmieniać!

//Spróbować skompilować za pomocą: gcc main.c -L./lib -lfun1 -lfun2
//Jaki jest wynik i dlaczego?

#include <stdio.h>

#include "lib/fun2.h"
#include "lib/fun2.h"

int main (void){
    fun2();
    return 0;
}

/* wynik działania
biblioteka
statyczna

*/
