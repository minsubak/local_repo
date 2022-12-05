/**
 * @file    selection_sort.h
 * @author  mindou (minsu5875@naver.com)
 * @brief   selection sort에 대한 설명
 *          
 *          [개요]
 *          왼쪽 리스트와 오른쪽 리스트 두개가 존재한다고 가정할 때, 왼쪽 리스
 *          트는 정렬된 숫자들, 오른쪽 리스트는 정렬되지 않은 숫자들이 저장되
 *          며 초기엔 왼쪽 리스트가 공백
 *          오른쪽 리스트에서 가장 작은 숫자를 왼쪽 리스트로 이동시키는 작업을
 *          되풀이
 *          
 * @version null
 * @date    last update: 2022-12-06
 * 
 * @copyright Copyright (c) Mindou 2022
 * 
 */
#ifndef SELECTION_H
#define SELECTION_H

#include "main.h"

/**
 * @brief 선택 정렬 | Time complexity: O(n^2)
 * 
 * @param list int data array
 * @param n    count
 */
void selection_sort(int list[], int n) {
    int tmp;
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++)  // 최솟값 탐색
            if(list[j] < list[min]) min = j;
        SWAP(list[i], list[min], tmp);
    }
}

#endif