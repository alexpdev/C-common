#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int main(char *argc, char **argv){
    int i = 12;

    printf("i = %d\n", i);

    int *ptr;

    ptr = &i;

    int j = *ptr;
    printf("ptr = %d\n", ptr);
    printf("ptr = %s\n", (char *)ptr);

    printf("val = %d\n", *ptr);
    printf("val = %d\n", *ptr);

    printf("j = %d\n", j);
    return 0;

}
