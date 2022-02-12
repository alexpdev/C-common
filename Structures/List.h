// List

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef void *Val;

typedef struct List {
    Val *values;
    unsigned size;
    unsigned length;
} List;

typedef int (* ValCompFunc)(Val val1, Val val2);

List *listInit(unsigned length);
bool listFree(List *list);
bool listAppend(List *list, Val element);
bool listDelete(List *list, unsigned index);
bool listRemove(List *list, Val element);
bool listInsert(List *list, unsigned index, Val element);
int listIndex(List *list, Val element);
Val listPop(List *list);



#endif
