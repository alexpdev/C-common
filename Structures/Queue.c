#include <stdlib.h>
#include <Queue.h>

typedef struct _QueueNode {
    void *data;
    QueueNode *next;
    QueueNode *prev;
}

struct _Queue {
    int size;
    QueueNode *start;
    QueueNode *end;
}

Queue *queueInit()
{
    Queue *queue;
    queue = (Queue *)malloc(sizeof(Queue))
    queue->size = 0;
    queue->start = NULL;
    queue->end = NULL;
    return queue;
}

void queuePush(Queue *queue, void *item){
    QueueNode *node;
    node = (QueueNode *)malloc(sizeof (QueueNode));
    node->data = item;
    QueueNode *start = queue->start;
    node->next = start;
    queue->start = node;
    return;

}
