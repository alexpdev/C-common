// List

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef void *Val;

typedef struct PList {
    Val *values;
    unsigned size;
    unsigned length;
} PList;

typedef int (* ValCompFunc)(Val val1, Val val2);

List *PListInit(unsigned length);
bool PListFree(PList *list);
bool PListAppend(PList *list, Val element);
bool PListDelete(PList *list, unsigned index);
bool PListRemove(PList *list, Val element);
bool PListInsert(PList *list, unsigned index, Val element);
int PListIndex(PList *list, Val element);
Val PListPop(PList *list);



#endif
