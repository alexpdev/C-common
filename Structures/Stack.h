#ifndef STACK_H
#define STACK_H

typedef struct StackNode {
    void *data;
    struct StackNode *next;
} StackNode;

typedef struct Stack {
    int count;
    StackNode *start;
} Stack;

Stack *StackInit();
void StackPush(Stack *stack, void *item);
void *StackPop(Stack *stack);
void StackPeek(Stack *stack);
void StackFree(Stack *stack);
