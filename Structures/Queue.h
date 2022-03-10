
#ifndef QUEUE_H
#define QUEUE_H


typedef struct Queue _Queue;
typedef struct QueueNode _QueueNode;

Queue *QueueInit();
void *QueuePop(Queue *queue);
void *QueuePeek(Queue *queue);
void QueuePush(Queue *queue, void *value);
void QueueFree(Queue *queue);

#endif
