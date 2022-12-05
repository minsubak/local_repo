/**
 * @file    shell_sort.h
 * @author  mindou (minsu5875@naver.com)
 * @brief   shell sort에 대한 설명
 * 
 *          [개요]
 *          삽입 정렬이 어느 정도 정렬이 되어 있는 배열에 대해 빠른 속도
 *          로 연산이 되는 것에 착안하여, 요소들이 삽입될 때, 이웃한 위
 *          치로만 이동이 가능한 삽입 정렬의 최대 문제점을 개선하기 위해
 *          먼 위치의 이동이 가능하도록 고안된 알고리즘
 *          셀 정렬은 정렬해야할 리스트를 일정한 기준에 맞춰 나누어 연속
 *          적이지 않은 여러 개의 부분 리스트를 만들고 삽입 정렬을 하고
 *          다시 더 적은 개수의 부분 리스트로 나누는 작업을 부분 리스트
 *          의 개수가 1이 될 때까지 되풀이
 * 
 * @version null
 * @date    last update: 2022-12-06
 * 
 * @copyright Copyright (c) Mindou 2022
 * 
 */
#ifndef SHELL_H
#define SHELL_H

/**
 * @brief 쉘 정렬 부속 함수(삽입)
 * 
 * @param list  int data array
 * @param first first sort pos
 * @param last  last sort pos
 * @param gap   gap of first and last
 */
void inc_insertion_sort(int list[], int first, int last, int gap){
    int j;
    for(int i = first+gap; i <= last; i = i+gap) {
        int key = list[i];
        for(j = i - gap; j >= first && key < list[j]; j= j-gap)
            list[j+gap] = list[j];
        list[j+gap] = key;
    }
}

/**
 * @brief 쉘 정렬 | Time complexity: O(n^1.5) ~ O(n^2)
 * 
 * @param list int data array
 * @param n    count
 */
void shell_sort(int list[], int n){
    /** gap은 list의 개수의 절반 */
    for(int gap = n/2; gap > 0; gap = gap/2) {
        /** gap이 짝수 값일 경우 1증가 시켜 홀수로 변경 */
        if((gap % 2) == 0) gap++;
        for(int i = 0; i < gap; i++)
            inc_insertion_sort(list, i, n-1, gap);
    }
}

#endif