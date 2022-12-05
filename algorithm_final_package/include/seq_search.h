/**
 * @file    seq_search.h
 * @author  mindou (minsu5875@naver.com)
 * @brief   seq_search에 대한 설명
 *          
 *          [개요]
 *          정렬되어있지 않은 배열의 항목을 모두 검사해 원하는 항목을 찾는 알고리즘
 * 
 * @version null
 * @date    last update: 2022-12-06
 * 
 * @copyright Copyright (c) Mindou 2022
 * 
 */
#ifndef SEQ_H
#define SEQ_H

/**
 * @brief 순차 탐색 | 정렬되어 있지 않은 배열의 항목들을 처음부터 끝까지 검사
 * 
 * @param list int data array
 * @param key  search target
 * @param low  search pos-low
 * @param high search pos-high
 * @return int 
 */
int seq_search(int list[], int key, int low, int high) {
    for(int i = low; i <= high; i++)
        if(list[i] == key)
            return i;
    return -1;
}

/**
 * @brief 순차 탐색(개선 버전) | 비교 횟수 감소
 * 
 * @param list int data array
 * @param key  search target
 * @param low  search pos-low
 * @param high search pos-high
 * @return int 
 */
int better_seq_search(int list[], int key, int low, int high) {
    int i;
    list[high+1] = key;
    for(i = low; list[i]!= key; i++);
    
    if(i == (high+1)) return -1;
    else return i;
}

#endif