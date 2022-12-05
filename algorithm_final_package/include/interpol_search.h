/**
 * @file    interpol_search.h
 * @author  mindou (minsu5875@naver.com)
 * @brief   interpol_search에 대한 설명
 * 
 *          [개요]
 *          전화번호부처럼 탐색키의 위치를 예측하는 알고리즘
 *          이진탐색과 유사하나 리스트를 분할할 때, 불균등하게 분할하는 것이 큰
 *          차이점
 * 
 *          [공식]
 *          target_pos = (k-list[low]) / list[high]-list[low] = *(high-low)+low
 *          [비례식]
 *          (list[high]-list[low]) : (k-list[low])=(high-low):(target_pos-low)
 *          [예시]
 *          번호: 0  1   2   3   4   5   6   7   8   9
 *          배열: 3, 9, 15, 22, 31, 55, 67, 88, 89, 91 | k = 55
 *          target_pos = (55-3)/(91-3)*(9-0)+0 = 5.31 = 5
 * 
 * @version null
 * @date    last update: 2022-12-06
 * 
 * @copyright Copyright (c) Mindou 2022
 * 
 */
#ifndef INTERPOL_H
#define INTERPOL_H

int interpol_search(int list[], int key, int n) {

    int high = n - 1;
    int low = 0;
    while((list[high] >= key) && (key > list[low])) {
        int j = ((float)(key-list[low]) / (list[high]-list[low]) * (high-low)) + low;
        if(key > list[j]) low = j + 1;
        else if(key < list[j]) high = j - 1;
        else low = j;
    }
    if(list[low] == key) return(low);       // 탐색 성공
    else return -1;                         // 탐색 실패
}

#endif