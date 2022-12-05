/**
 * @file    binary_search.h
 * @author  mindou (minsu5875@naver.com)
 * @brief   binary_search에 대한 설명
 * 
 *          [개요]
 *          배열의 중앙에 있는 값을 조사해 찾고자 하는 항목이 왼쪽 또는 오른쪽
 *          부분 배열에 있는지를 알아내어 탐색 범위를 줄이는 알고리즘
 *          단, 배열은 정렬 상태
 * 
 * @version null
 * @date    last update: 2022-12-06
 * 
 * @copyright Copyright (c) Mindou 2022
 * 
 */
#ifndef BINARY_H
#define BINARY_H

/**
 * @brief 이진 탐색(재귀) | 탐색 범위를 절반 씩 줄여 비교 횟수를 감소
 * 
 * @param list int data array
 * @param key  search target
 * @param low  search pos-low
 * @param high search pos-high
 * @return int 
 */
int binary_search_recu(int list[], int key, int low, int high) {

    int middle;
    if(low <= high) {
        middle = (low + high) / 2;
        if (key == list[middle])    // 탐색 성공
            return middle;
        else if (key < list[middle]) // 왼쪽 부분리스트 탐색
            return binary_search_recu(list, key, low, middle - 1);
        else                        // 오른쪽 부분리스트 탐색
            return binary_search_recu(list, key, middle + 1, high);
    }
    return -1;                      // 탐색 실패
}

/**
 * @brief 이진 탐색(반복) | 탐색 범위를 절반 씩 줄여 비교 횟수를 감소
 * 
 * @param list int data array
 * @param key  search target
 * @param low  search pos-low
 * @param high search pos-high
 * @return int 
 */
int binary_search_iter(int list[], int key, int low, int high) {
    int middle;

    while(low <= high) {            // 숫자가 남아있는 동안
        middle = (low + high) / 2;
        if (key == list[middle])    // 탐색 성공
            return middle;
        else if (key > list[middle])// 왼쪽 부분리스트 탐색
            low = middle + 1;
        else                        // 오른쪽 부분리스트 탐색
            high = middle - 1;
    }
    return -1;                      // 탐색 실패
}

#endif