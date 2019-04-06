//przykład demonstrujący tworzenie biblioteki statycznej i dołączanie jej do projektu 
//oraz prostych opercji na niej

//utowrzona biblioteka jest niezależna od plików obiektowych,
//z których powstała, gdy zmienimy je, dopóki nie utowrzymy biblioteki na nowo
//lub jej nie odświerzymy zmiany nie zostana wprowadzone

//przydatne komendy
//https://linux.die.net/man/1/ar
//ar r - dodanie pliku do archiwum
//ar c - stworzenie archiwum
//ar t - wylistowanie plików w archiwum
//nm - wylistowanie ze zdefiniowanymi symbolami
//ar x - wypakowanie plików
//ar d - usunięcie modułu z archiwum

#include <stdio.h>

#include "lib/plik1.h"
#include "lib/plik2.h"

int main(void){
    whisper("bIBLioTeKa");
    shout("StaTYcZnA");
    return 0;
}