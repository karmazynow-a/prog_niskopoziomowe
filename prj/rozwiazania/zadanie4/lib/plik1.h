#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int typ1;
typedef void typ2;
typedef float typ3;
typedef char * typ4;

typ2 fun1 (typ1 i);
typ3 fun2 (typ3 i);
typ2 fun3 (typ4 i);
typ4 fun4 (typ1 i);
typ2 fun5 (typ1 i);
typ1 fun6 (typ3 i);
