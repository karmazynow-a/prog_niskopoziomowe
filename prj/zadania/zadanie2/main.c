//Zadaniem jest napisanie prostego systemu wtyczek
//Zakładamy że nazwy wtyczek podane są w tablicy plugins w main, i znajdują się w folderze o tej samej nazwie
//Program powinien przyjmować od użytkownika ciąg znaków (jako argument wywołania lub 
//przez sprintf)
//Wtyczki powinny być dwie i realizować różne działania na owym stringu i wypisywać je na ekran
//np zamieniać wszystkie litery na wielkie, mieszać kolejność liter, wypisywać tylko 
//samogłoski, wypisywać wyraz od tyłu etc
//Należy pamiętać o uzupełnieniu makefile!

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, const char* argv[]) {

    //przygotuj ścieżki do wtyczek

    //ustal jaką deklarację będą miały zaczepione funkcje
    //dla ułatwienia w późniejszym użyciu możesz użyć typedefa np:
    //typedef char * (*process_plugin) (char *);

    //w pętli otwórz połączenie i wywołaj zaczepione funkcje dla kolejnych wtyczek
    //pamiętaj o zamknięciu połączenia 

    return 0;
}

