//przykład demonstrujący niezależność utowrzonej biblioteki od plików obiektowych,
//z których powstała, gdy zmienimy je, dopóki nie utowrzymy biblioteki na nowo
//lub jej nie odświerzymy zmiany nie zostana wprowadzone

#include <stdio.h>

#include "lib/plik1.h"
#include "lib/plik2.h"

int main(void){
    whisper("bIBLioTeKa");
    shout("StaTYcZnA");
    return 0;
}