#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "Stack.h"

Stack *initStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    stack->first = node;
    stack->last = node;
    stack->count = 0;
    return stack;
}

void stackPush(Stack *stack, void *item)
{
    StackNode *data = (StackNode *)malloc(sizeof StackNode);
    data->data = item;
    data->next = stack->first;
    stack->first = data;
    stack->count = stack->count + 1;
    return;
}

void *stackPop(Stack *stack)
{
    StackNode *item;
    item = stack->first;
    stack->first = item->next;
    void *value;
    value = item->data;
    stack->count = stack->count - 1;
    return value;
}

void *stackPeak(Stack *stack)
{
    StackNode *item;
    item = stack->first;
    void *value;
    value = item->data;
    return value;
}

void stackFree(Stack *stack)
{
    StackNode *current;
    StackNode *next;
    while (stack->count > 1)
    {
        current = stack->first;
        next = current->next;
        free(current);
        stack->first = next;
        stack->count -= 1;
    }
    free(stack);
}
