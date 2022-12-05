/**
 * @file    insertion_sort.h
 * @author  mindou (minsu5875@naver.com)
 * @brief 
 * @version null
 * @date    last update: 2022-12-05
 * 
 * @copyright Copyright (c) Mindou 2022
 * 
 */
#ifndef INSERTION_H
#define INSERTION_H

/**
 * @brief 삽입 정렬 | Time complexity: O(n^2)
 * 
 * @param list int data array
 * @param n    count
 */
void insertion_sort(int list[], int n) {
    int j, tmp;
    for (int i = 0; i < n; i++) {
        tmp = list[i];
        for(j = i - 1; j >= 0 && list[j] > tmp; j--)
            list[j + 1] = list[j];
        list[j+1] = tmp;
    }
}

#endif