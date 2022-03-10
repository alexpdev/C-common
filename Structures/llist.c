#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

Node *newNode(void *data, int size)
{
    Node *node = (Node *)malloc(sizeof(Node) + size);
    assert(node);
    node->data = data;
    node->size = size;
    node->next = NULL;
    return node;
}

Node *emptyNode()
{
    return (Node *)malloc(sizeof(Node));
}

void LListShow(Node *node)
{
    Node *current = node;
    if(!node) return;
    while (current != NULL){
        current = current->next;
        printf("%s\n", (char *)current->data);
    }
}

void LListAppend(LList *list, Node *next)
{
    Node *last_node = list->end;
    last_node->next = next;
}


void LListDelete(LList *list, Node *node)
{
    Node *previous = top;
    Node *current = top->next;
    while(current != NULL){
        if(current->data == data){
            previous->next = current->next;
            if(current == top)
                top = current->next;
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void LListDestroy(LList *list)
{
    Node *next;
    Node *current = top;
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    free(top);
}
