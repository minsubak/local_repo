/**
 * @file    bubble_sort.h
 * @author  mindou (minsu5875@naver.com)
 * @brief   bubble sort에 대한 설명
 * 
 *          [개요]
 *          인접한 2개의 레코드를 비교 및 교환하는 과정을 리스트 왼쪽
 *          끝에서부터 리스트 오른쪽 끝까지 연산하는 알고리즘
 *          
 * @version null
 * @date    last update: 2022-12-06
 * 
 * @copyright Copyright (c) Mindou 2022
 * 
 */
#ifndef BUBBLE_H
#define BUBBLE_H

#include "main.h"

/**
 * @brief 버블 정렬 | Time complexity: O(n^2)
 * 
 * @param list int data array
 * @param n    count
 */
void bubble_sort(int list[], int n) {
    int tmp;
    for(int i = n - 1; i> 0; i--) {
        for(int j = 0; j < i; j++) 
            if(list[j] > list[j+1])
                SWAP(list[j], list[j+1], tmp);
    }
}

#endif