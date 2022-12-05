/**
 * @file    merge_sort.h
 * @author  mindou (minsu5875@naver.com)
 * @brief   merge_sort에 대한 설명
 * 
 *          [개요]
 *          하나의 리스트를 두 개의 균등한 크기로 분활하고 정렬한 다음
 *          다시 하나의 리스트로 합해 전체가 정렬된 리스트를 얻고자 하
 *          는 알고리즘
 *          분할 정복(divide and conquer) 기법에 바탕
 *          이 기법은 문제를 2개의 문제로 분리, 각각 해결 후 다시 모아
 *          원래의 문제를 해결하는 전략
 *          만약 분리된 문제의 해결이 어렵다면, 다시 2개의 문제로 나누
 *          는 과정을 반복해 다시 적용
 *          재귀 함수(순환 호출)로 구현
 *          안정적이지만 더 많은 메모리 필요(임시 배열)
 * 
 * @version null
 * @date    last update: 2022-12-06
 * 
 * @copyright Copyright (c) Mindou 2022
 * 
 */

#ifndef MERGE_H
#define MERGE_H

#include "main.h"

int sorted[MAX/4]; // 합병 정렬을 위한 별도의 공간

/**
 * @brief 분할된 부분 리스트 합병 연산
 * 
 * @param list  int data array
 * @param left  data count(min)
 * @param mid   data cound(mid)
 * @param right data count(max)
 */
void merge(int list[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    /* 
       i: 정렬된 왼쪽 리스트에 대한 인덱스
       j: 정렬된 오른쪽 리스트에 대한 인덱스
       k: 정렬된 리스트에 대한 인덱스       
    */

    /* 분할 정렬된 list 합병 */
    while(i <= mid && j <= right) {
        if(list[i] <= list[j])
            sorted[k++] = list[i++];
        else 
            sorted[k++] = list[j++];
    }
    if(i > mid)     /* 남아있는 레코드 일괄 복사 */
        for(int l = j; l <= right; l++)
            sorted[k++] = list[l];
    else            /* 남아있는 레코드 일괄 복사 */
        for(int l = i; l <= mid; l++)
            sorted[k++] = list[l];
    /* 배열 sorted[]의 리스트를 비열 list[]로 재복사 */
    for(int l = left; l <= right; l++)
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