#include <string.h>
#include <stdio.h>

char * process_string (char * s){
    int i;
    for (i=0; i<strlen(s)/2; ++i){
        char tmp = s[i];
        s[i] = s[strlen(s) -1 - i];
        s[strlen(s) -1 - i] = tmp;
    }

    return s;
}