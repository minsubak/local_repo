/**
 * @file    
 * @author  mindou (minsu5875@naver.com)
 * @brief 
 * @version null
 * @date    last update: 2022-12-05
 * 
 * @copyright Copyright (c) Mindou 2022
 * 
 */
#ifndef RADIX_H
#define RADIX_H

#include "queue.h"

/**
 * @brief 기수 정렬 | Time complexity: O(d*n) ~ o(n)
 * 
 * @param list int data array
 * @param n    data count
 */
void radix_sort(int list[], int n) {
    QueueType q[BUCKETS];
    int factor = 1;

    for(int b = 0; b < BUCKETS; b++) init_queue(&q[b]);

    for(int d = 0; d < DIGITS; d++) {
        int i;
        for(i = 0; i < n; i++)
            enqueue(&q[(list[i]/factor)%10], list[i]);
        
        for(int b = 0; b < BUCKETS; b++)
            while(!is_empty(&q[b]))
                list[i++] = dequeue(&q[b]);
        factor *= 10;
    }
}

#endif