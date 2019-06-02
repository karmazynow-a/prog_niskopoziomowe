#include "plik1.h"
#include <string.h>
#include "plik1.h"
#include <stdlib.h>

typ2 fun1 (typ1 i){
    puts("fun1");
}

typ3 fun2 (typ3 i){
    puts("fun2");
    return i + 10.0;
}

typ2 fun3 (typ4 i){
    puts("fun3");
}

typ4 fun4 (typ1 i){
    puts("fun4");
    return "tak";
}

typ2 fun5 (typ1 i){
    puts("fun5");
}

typ1 fun6 (typ3 i){
    puts("fun6");
    return 1;
}