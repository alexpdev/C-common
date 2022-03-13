#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ilist.h"

// Integer List
IList* IListInitN(int n){
    IList *list = malloc(sizeof(iList));
    int capacity = n + 1;
    if (n == 0) capacity = 12;
    int *array = calloc(capacity, sizeof(int));
    int length = 0;
    list->array = array;
    list->capacity = capacity;
    list->length = length;
    return list;
}

IList* IListInit(){
    return iListInitN(0);
}

void IListExpand(IList *list){
    int capacity = list->capacity;
    int *array = calloc(capacity*2, sizeof(int));
    for (int i=0; i<list->length; i++){
        array[i] = list->array[i];
    }
    int *old = list->array;
    list->array = array;
    list->capacity = capacity*2;
    free(old);
}

void IListInsert(IList *list, int index, int n){
    if (list->length >= list->capacity-1) IListExpand(list);
    int other = index;
    int l = list->length;
    while (l > other){
        list->array[l] = list->array[l-1];
        l -= 1;
    }
    list->array[index] = n;
    list->length += 1;
}

void IListAppend(IList* list, int n){
    IListInsert(list, list->length, n);
}


void IListDelete(IList *list, int index){
    while (index < list->length - 1){
        list->array[index] = list->array[index + 1];
        index += 1;
    }
    list->length -= 1;
}

void IListRemove(IList* list, int n){
    int index;
    for (index=0; index<list->length; index++)
        if (list->array[index] == n)
            break;
    IListDelete(list, index);
}

void IListFree(IList* list){
    free(list->array);
    free(list);
}

int IListGet(IList *list, int index){
    return list->array[index];
}

void IListShow(IList *list){
    printf("[");
    for (int i=0; i < list->length; i++){
        printf("%d, ", list->array[i]);
    }
    printf("]\n");
}

iList *IListSub(IList* list, int start, int stop){
    int capacity = start - stop;
    iList *sub = IListInitN(capacity);
    for (int i=0; i<capacity; i++){
        sub->array[i] = list->array[start];
        start += 1;
    }
    return sub;
}
