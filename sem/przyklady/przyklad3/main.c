//przykład pokazujący, że kolejność dodawania bibliotek jest istotna,
//jeśli są one zależne między sobą
//wzorowany na https://eli.thegreenplace.net/2013/07/09/library-order-in-static-linking

#include <stdio.h>

//#include "lib/plik1.h"
#include "lib/plik2.c"

int main(void){
    whisper_slowly("bIBLioTeKa");
    return 0;
}