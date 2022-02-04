#include <stdlib.h>
#include <string.h>
#include "list.h"


List *listInit(unsigned length)
{
    // Create a new specified length list with no elements.
    List *list;
    if (length <= 0)
        length = 12;
    list = (List *) malloc(sizeof List);
    if !(list) return NULL;
    list->size = length;
    list->length = 0;
    list->values = malloc(length * sizeof(Val));
    if !(list->data)
    {
        free(list);
        return NULL;
    }
    return list;
}


void listFree(List *list)
{
    // Free the memory allocated to the list
    if (list != NULL)
    {
        free(list->values);
        free(list);
    }
}


bool listExpand(List *list)
{
    // Expand capacity of list
    unsigned capacity;
    Val *vals;
    capacity = list->size * 2;
    vals = realloc(list->values, capacity * sizeof(Val));
    if !(vals) return false;
    list->values = vals;
    list->size = capacity;
    return true;
}


bool listInsert(List *list, unsigned index, Val value)
{
    // insert value at a specific index within the list
    if (index > list->length) return false;
    if (list->length + 1 >= list->size)
    {
        if (!listExpand(list))
            return false;
    }
    if (index == list->length)
    {
        list->values[list->length] = value;
        list->length += 1;
        return true;
    }
    for (int i = list->length; i > index; i--)
    {
        list->values[i] = list->values[i-1];
    }
    list->values[index] = value;
    return true;
}


bool listAppend(List *list, Val value)
{
    // add element to end of the list;
    return listInsert(list, list->length, value);
}


int listIndex(List *list, Val val, ValCompFunc func)
{
    // find the index of a particular element within list.
    for (int i=0; i < list->length; i++)
    {
        int result = func(val, list->values[i]);
        if (result == 0) return i;
    }
    return -1;
}


bool listDelete(List *list, unsigned index)
{
    // delete element at specific index of the array.
    if (index > list->length) return false;
    for (int i = index; i < list->length - 1; i++)
    {
        list->values[i] = list->values[i+1];
    }
    list->length -= 1;
    return true;
}


bool listRemove(List *list, Val value, ValCompFunc func)
{
    // remove the first index of the list where the value equals specified val.
    int index;
    index = listIndex(list, value, func);
    if (index == -1) return false;
    return listDelete(list, index);
}


Val listPop(List list)
{
    // remove last element of list and return it.
    Val value;
    unsigned index = list->length - 1;
    value = list->values[index];
    list->length = index;
    return value;
}


void listReset(List list)
{
    // Empty the provided list
    list->length = 0;
}
