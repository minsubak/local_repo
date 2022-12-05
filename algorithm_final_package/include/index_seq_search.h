/**
 * @file    index_seq_search.h
 * @author  mindou (minsu5875@naver.com)
 * @brief   index_seq_search에 대한 설명
 * 
 *          [개요]
 *          색인 순차 탐색은 인덱스라 불리는 테이블을 사용해 탐색의 효울을
 *          높이는 알고리즘
 * 
 *          [동작 방법]
 *          인덱스 테이블은 주 자료 리스트에서 일정 간격으로 발췌한 자료를
 *          보유(인덱스 테이블: m개, 주 자료리스트: n개 -> 각 인덱스 항목
 *          은 주 자료리스트의 각 n/m번째 데이터를 보유)
 *          인덱스 테이블에서 index[i] <= key < index[i+1]을 만족하는 항
 *          목을 주 자료리스트에서 순차 탐색을 수행
 * 
 * @version null
 * @date    last update: 2022-12-06
 * 
 * @copyright Copyright (c) Mindou 2022
 * 
 */
#ifndef INDEXED_H
#define INDEXED_H

#define INDEX_SIZE 256
#include "seq_search.h"

typedef struct {
    int key;
    int index;
} itable;
itable index_list[INDEX_SIZE];

int index_seq_search(int list[], int key, int n) {
    
    int i, low, high;

    /** 키 값이 리스트 범위 내 값이 아닐 경우 종료 */
    if (key<list[0] || key>list[n-1])
        return -1;
    
    /** 인덱스 테이블을 조사해 해당키의 구간 결정 */
    for(i = 0; i < INDEX_SIZE; i++)
        if(index_list[i].key <= key && index_list[i+1].key > key)
            break;
    if(i == INDEX_SIZE) {
        low = index_list[i-1].index;
        high = n;
    } else {
        low = index_list[i].index;
        high = index_list[i + 1].index;
    }
    /** 예상범위만 순차 탐색 */
    return better_seq_search(list, key, low, high);
}

#endif