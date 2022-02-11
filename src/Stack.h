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

Stack *initStack();
void stackPush(Stack *stack, void *item);
void *stackPop(Stack *stack);
void stackPeek(Stack *stack);
void stackFree(Stack *stack);
