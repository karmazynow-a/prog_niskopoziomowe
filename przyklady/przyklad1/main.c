//przykład demonstrujący tworzenie biblioteki statycznej i dołączanie jej do projektu
//użyty został pomocniczy skrytp create.sh

//polecenie ar t ./lib/liblib.a - pokazuje zawartość biblioteki
//polecenie ar x ./lib/liblib.a - wypakowywuje zawartość biblioteki

#include <stdio.h>

#include "lib/plik1.h"
#include "lib/plik2.h"

int main(void){
    whisper("bIBLioTeKa");
    shout("StaTYcZnA");
    return 0;
}