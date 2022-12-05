/**
 * @file    radix_sort.h
 * @author  mindou (minsu5875@naver.com)
 * @brief   radix_sort에 대한 설명
 *          
 *          [개요]
 *          타 정렬 알고리즘과 달리 레코드를 비교하지 않고도 정렬하는 방법
 *          입력 데이터에 대해서 어떤 비교 연산도 실행하지 않고 데이터를 
 *          정렬할 수 있는 색다른 정렬 알고리즘
 *          기수 정렬의 단점은 정렬할 수 있는 레코드의 타입이 한정적
 * 
 *          [동작 방식]
 *          10진수에서 0~9까지의 값을 가지는 것을 착안해 10개의 버킷을 만
 *          들어 입력 데이터를 각 자리수의 값에 따라 넣고 왼쪽 상자부터 순
 *          차적으로 버킷 안에 있는 숫자를 읽으면 정렬된 숫자 도출
 * 
 * @version null
 * @date    last update: 2022-12-06
 * 
 * @copyright Copyright (c) Mindou 2022
 * 
 */
#ifndef RADIX_H
#define RADIX_H

#include "queue.h"

/**
 * @brief 기수 정렬 | Time complexity: o(n) ~ O(k*n) | k<4
 *        (최대 2자리까지)
 * 
 * @param list int data array
 * @param n    data count
 */
void radix_sort(int list[], int n) {
    QueueType q[BUCKETS];
    int factor = 1; // 자리수

    for(int b = 0; b < BUCKETS; b++) 
        init_queue(&q[b]); // 큐 초기화

    for(int d = 0; d < DIGITS; d++) {                   // 데이터의 자리수에 따라 큐 삽입
        int i;
        for(i = 0; i < n; i++)
            enqueue(&q[(list[i]/factor)%10], list[i]);
        
        for(int b = i = 0; b < BUCKETS; b++)                // 버킷에서 꺼내 list에 삽입
            while(!is_empty_q(&q[b]))
                list[i++] = dequeue(&q[b]);
        factor *= 10;                                   // 다음 자리수로 이동
    }
}

#endif