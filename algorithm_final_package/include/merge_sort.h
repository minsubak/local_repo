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

#ifndef MERGE_H
#define MERGE_H

#include "main.h"

int sorted[MAX/10]; // 합병 정렬을 위한 별도의 공간

/**
 * @brief 합병 정렬 부속 함수(합병)
 * 
 * @param list  int data array
 * @param left  data count(min)
 * @param mid   data cound(mid)
 * @param right data count(max)
 */
void merge(int list[], int left, int mid, int right) {
    int i, j, k, l;
    i = left; j = mid + 1; k = left;
    /* 
       i: 정렬된 왼쪽 리스트에 대한 인덱스
       j: 정렬된 오른쪽 리스트에 대한 인덱스
       k: 정렬된 리스트에 대한 인덱스       */

    /* 분할 정렬된 list 합병 */
    while(i <= mid && j <= right) {
        if(list[i] <= list[j])
            sorted[k++] = list[i++];
        else 
            sorted[k++] = list[j++];
    }
    if(i < mid)     /* 남아있는 레코드 일괄 복사 */
        for(l = j; l <= right; l++)
            sorted[k++] = list[l];
    else            /* 남아있는 레코드 일괄 복사 */
        for(l = i; l <= mid; l++)
            sorted[k++] = list[l];
    /* 배열 sorted[]의 리스트를 비열 list[]로 재복사 */
    for(l = left; l <= right; l++)
        list[l] = sorted[l];
}

/**
 * @brief 합병 정렬 | Time complexity: O(nlog2n)
 * 
 * @param list  int data array
 * @param left  data count(min)
 * @param right data count(max)
 */
void merge_sort(int list[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;   // list 균등 분할
        merge_sort(list, left, mid);    // 부분 list 정렬
        merge_sort(list, mid+1, right); // 부분 list 정렬
        merge(list, left, mid, right);  // 합병
    }
}

#endif