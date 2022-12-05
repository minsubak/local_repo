/**
 * @file    
 * @author  mindou (minsu5875@naver.com)
 * @brief 
 * @version null
 * @date    last update: 2022-12-05
 * 
 * @copyright Copyright (c) Mindou 2022
 * 
 */

#ifndef QUICK_H
#define QUICK_H

/**
 * @brief 퀵 정렬 부속 함수(분할)
 * 
 * @param list  int data array
 * @param left  data count(min)
 * @param right data count(max)
 * @return int 
 */
int partition(int list[], int left, int right) {
    int pivot, temp, low, high;

    low = left;
    high = right + 1;
    pivot = list[left];
    do {
        do
            low++;
        while(list[low] < pivot);
        do
            high--;
        while(list[high] > pivot);
        if(low < high) {
            temp = list[low];
            list[low] = list[high];
            list[high] = temp;
        }
    } while(low < high);
    temp = list[left];
    list[left] = list[high];
    list[high]= temp;
    return high;
}

/**
 * @brief 퀵 정렬 | Time complexity: O(nlog2n)
 * 
 * @param list  int data array
 * @param left  data count(min)
 * @param right data count(max)
 */
void quick_sort(int list[], int left, int right) {
    if(left < right) {
        int q = partition(list, left, right);
        quick_sort(list, left, q - 1);
        quick_sort(list, q + 1, right);
    }
}

#endif