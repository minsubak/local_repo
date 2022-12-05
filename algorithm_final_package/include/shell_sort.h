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
    int key;
    for(int i = first+gap; i <= last; i = i+gap) {
        key = list[i];
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
    for(int gap = n/2; gap > 0; gap = gap/2) {
        if((gap % 2) == 0) gap++;
        for(int i = 0; i < gap; i++) {
            inc_insertion_sort(list, i, n-1, gap);
    }}
}

#endif