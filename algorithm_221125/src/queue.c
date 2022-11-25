#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void init_queue(QueueType *q) {
    q->front = q->rear = 0;
}

bool is_empty(QueueType *q) {
    if(q->front == q->rear) return true;
    else false;
}

bool is_full(QueueType *q) {
     if(q->front == (q->rear+1) % MAX_Q) return true;
     else false;
}

void enqueue(QueueType *q, element item) {
    if(is_full(q)) {
        fprintf(stderr, "queue is full!\n");
        exit(1);
    }
    q->rear = (q->rear + 1) % MAX_Q;
    q->queue[q->rear] = item;
}

element dequeue(QueueType *q) {
    if(is_empty(q)) {
        fprintf(stderr, "queue is empty!\n");
        exit(1);
    }
    q->front = (q->front + 1) % MAX_Q;
    return q->queue[q->front];
}