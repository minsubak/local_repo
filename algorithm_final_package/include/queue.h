#ifndef QUEUE_H
#define QUEUE_H

#define BUCKETS 10
#define DIGITS  4
#define MAX_Q   20

#include <stdbool.h>

typedef int element_q;

typedef struct QueueType {
    int front, rear;
    element_q queue[MAX_Q];
}QueueType;

void init_queue(QueueType *q);

bool is_empty(QueueType *q);

bool is_full(QueueType *q);

void enqueue(QueueType *q, element_q item);

element_q dequeue(QueueType *q);

#endif