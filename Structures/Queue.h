
#ifndef QUEUE_H
#define QUEUE_H


typedef struct Queue _Queue;
typedef struct QueueNode _QueueNode;

Queue *queueInit();
void *queuePop(Queue *queue);
void *queuePeek(Queue *queue);
void queuePush(Queue *queue, void *value);
void queueFree(Queue *queue);

#endif
