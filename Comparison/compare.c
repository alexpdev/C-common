#include <stdlib.h>
#include <string.h>
#include "compare.h"

int stringEqual(void *str1, void *str2)
{
    return strcmp((char *) str1, (char*) str2);
}

int stringComp(void *str1, void *str2)
{
    return stringEqual(str1, str2);
}

int pointerCmp(void *ptr1, void *ptr2)
{
    if (ptr1 == ptr2){
        return 0;
    }
    return -1;
}

int intCmp(void *n1, void *n2)
{
    int i, j;
    i = *n1;
    j = *n2;
    return i - j;
}
