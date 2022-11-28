#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void init_queue(QueueType *q) {
    q->front = q->rear = 0;
}

bool is_empty(QueueType *q) {
    return (q->front == q->rear);
}

bool is_full(QueueType *q) {
    return (q->front == (q->rear+1) % MAX_Q);
}

void enqueue(QueueType *q, element_q item) {
    if(is_full(q)) {
        fprintf(stderr, "queue is full!\n");
        exit(1);
    }
    q->rear = (q->rear + 1) % MAX_Q;
    q->queue[q->rear] = item;
}

element_q dequeue(QueueType *q) {
    if(is_empty(q)) {
        fprintf(stderr, "queue is empty!\n");
        return;
    }
    q->front = (q->front + 1) % MAX_Q;
    return q->queue[q->front];
}