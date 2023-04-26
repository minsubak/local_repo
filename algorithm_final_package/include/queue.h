/**
 * @file    queue.h
 * @author  Mindou (minsu5875@naver.com)
 * @brief   queue 자료구조
 *  
 *          [개요]
 *          기본 queue 자료구조
 * 
 * @version null
 * @date    last update: 2022-12-06
 * 
 * @copyright Copyright Mindou (c) 2022
 * 
 */
#ifndef QUEUE_H
#define QUEUE_H

//#define BUCKETS 10
//#define DIGITS  4
#define MAX     100

// #include "main.h"
#include <stdio.h>
#include <stdlib.h>

typedef int element_q;

typedef struct QueueType {
    int front, rear;
    element_q queue[MAX];
}QueueType;

void init_queue(QueueType *q) {
    q->front = q->rear = 0;
}

int is_empty_q(QueueType *q) {
    return (q->front == q->rear);
}

int is_full_q(QueueType *q) {
    return (q->front == (q->rear+1) % MAX);
}

void enqueue(QueueType *q, element_q item) {
    if(is_full_q(q)) {
        fprintf(stderr, "queue is full!\n");
        exit(1);
    }
    q->rear = (q->rear + 1) % MAX;
    q->queue[q->rear] = item;
}

element_q dequeue(QueueType *q) {
    if(is_empty_q(q)) {
        fprintf(stderr, "queue is empty!\n");
        return;
    }
    q->front = (q->front + 1) % MAX;
    return q->queue[q->front];
}

#endif