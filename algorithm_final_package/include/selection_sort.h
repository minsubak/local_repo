/**
 * @file    selection_sort.h
 * @author  mindou (minsu5875@naver.com)
 * @brief 
 * @version null
 * @date    last update: 2022-12-05
 * 
 * @copyright Copyright (c) Mindou 2022
 * 
 */
#ifndef SELECTION_H
#define SELECTION_H

/**
 * @brief 선택 정렬 | Time complexity: O(n^2)
 * 
 * @param list int data array
 * @param n    count
 */
void selection_sort(int list[], int n) {
    int tmp;
    for(int i = 0; i < n; i++) {
        int min = 1;
        for(int j = i + 1; j < n; j++) {
            if(list[j] < list[min])
                min = j;
        }
        tmp = list[i];
        list[i] = list[min];
        list[min] = tmp;
    }
}

#endif