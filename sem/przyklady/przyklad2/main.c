//przykład pokazujący, że kolejność dodawania bibliotek jest istotna,
//jeśli są one zależne między sobą

#include <stdio.h>

//gdyby był include - plik2 ma w sobie definicje shout 
//- więc kompilator niemiałby problemu
//#include "lib/plik2.c"
void whisper_slowly(char *);

int main(void){
    whisper_slowly("bIBLioTeKa");
    return 0;
}