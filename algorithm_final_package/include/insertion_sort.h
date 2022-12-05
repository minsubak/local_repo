/**
 * @file    insertion_sort.h
 * @author  mindou (minsu5875@naver.com)
 * @brief   insertion sort에 대한 설명
 *          
 *          [개요]
 *          카드 게임에서 손 안에 있는 카드를 정렬하는 것과 유사
 *          정렬되어 있는 리스트에 새로운 레코드를 적적한 위치에 삽입하는
 *          과정을 반복하는 알고리즘
 *          선택 정렬과 유사하게 입력 배열을 정렬된 부분과 정렬되지 않은 
 *          부분으로 나누어 사용
 *          
 * @version null
 * @date    last update: 2022-12-06
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
    int j;
    for (int i = 0; i < n; i++) {
        int tmp = list[i];
        for(j = i - 1; j >= 0 && list[j] > tmp; j--)
            list[j + 1] = list[j];  // 오른쪽 레코드로 이동
        list[j+1] = tmp;
    }
}

#endif