//Zadanie polega na dopisaniu brakującego pliku biblioteki, a potem stworzenie jej,
//aby można było skompilować program za pomocą komendy
//gcc main.c -L./lib -lfun2 -lfun1
//bez żadnych errorów/warningów
//plików main.c oraz fun1.c nie można zmieniać!

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