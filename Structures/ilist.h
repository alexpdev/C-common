#ifndef ILIST_H
#define ILIST_H

typedef struct IList {
    int *array;
    int capacity;
    int length;
} IList;

IList* IListInit();
IList* IListInitN(int n);
void IListInsert(IList* list, int index, int n);
void IListAppend(IList* list, int n);
void IListExpand(IList* list);
void IListRemove(IList* list, int n);
void IListDelete(IList* list, int index);
int IListGet(IList* list, int index);
void IListFree(IList* list);
void IListShow(IList *list);

#endif
