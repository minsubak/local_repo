/**
 * @file    bubble_sort.h
 * @author  mindou (minsu5875@naver.com)
 * @brief 
 * @version null
 * @date    last update: 2022-12-05
 * 
 * @copyright Copyright (c) Mindou 2022
 * 
 */
#ifndef BUBBLE_H
#define BUBBLE_H

/**
 * @brief 버블 정렬 | Time complexity: O(n^2)
 * 
 * @param list int data array
 * @param n    count
 */
void bubble_sort(int list[], int n) {
    int tmp;
    for(int i = n - 1; i> 0; i--) {
        for(int j = 0; j < i; j++) {
            if(list[j] < list[j+1]) {
                tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
            }
        }
    }
}

#endif