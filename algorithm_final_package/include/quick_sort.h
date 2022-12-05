/**
 * @file    quick_sort.h
 * @author  mindou (minsu5875@naver.com)
 * @brief   quick_sort에 대한 설명
 *          
 *          [개요]
 *          평균적으로 매우 빠른 수행 속도를 자랑하는 정렬 알고리즘이며
 *          분할 정복법에 근거
 *          합볍 정렬과 달리 리스트를 리스트 내의 한 요소를 피벗값으로
 *          비균등하게 분할하고 피벗 값을 기준으로 피벗값보다 작은 값은
 *          왼쪽 리스트, 큰 값은 오른쪽 리스트로 이동하는 것이 차이점
 * 
 * @version null
 * @date    last update: 2022-12-06
 * 
 * @copyright Copyright (c) Mindou 2022
 * 
 */

#ifndef QUICK_H
#define QUICK_H

#include "main.h"

/**
 * @brief 퀵 정렬 분할 연산
 * 
 * @param list  int data array
 * @param left  data count(min)
 * @param right data count(max)
 * @return int 
 */
int partition(int list[], int left, int right) {
    
    int tmp;
    int low = left;
    int high = right + 1;
    int pivot = list[left];
    do {
        do
            low++;
        while(list[low] < pivot);
        do
            high--;
        while(list[high] > pivot);
        if(low < high) 
        SWAP(list[low], list[high], tmp);
    } while(low < high);
    
    SWAP(list[left], list[high], tmp);
    return high;
}

/**
 * @brief 퀵 정렬 | Time complexity: O(nlog2n)
 * 
 * @param list  int data array
 * @param left  data count(min)
 * @param right data count(max)
 */
void quick_sort(int list[], int left, int right) {
    if(left < right) {
        int q = partition(list, left, right);
        quick_sort(list, left, q - 1);
        quick_sort(list, q + 1, right);
    }
}

#endif