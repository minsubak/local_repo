#ifndef SORT_H
#define SORT_H

#include "main.h"

/**
 * @brief 선택 정렬 | Time complexity: O(n^2)
 * 
 * @param list int data array
 * @param n    count
 */
void selection_sort(int list[], int n);

/**
 * @brief 삽입 정렬 | Time complexity: O(n^2)
 * 
 * @param list int data array
 * @param n    count
 */
void insertion_sort(int list[], int n);

/**
 * @brief 버블 정렬 | Time complexity: O(n^2)
 * 
 * @param list int data array
 * @param n    count
 */
void bubble_sort(int list[], int n);

/**
 * @brief 쉘 정렬 부속 함수(삽입)
 * 
 * @param list  int data array
 * @param first first sort pos
 * @param last  last sort pos
 * @param gap   gap of first and last
 */
void inc_insertion_sort(int list[], int first, int last, int gap);

/**
 * @brief 쉘 정렬 | Time complexity: O(n^1.5) ~ O(n^2)
 * 
 * @param list int data array
 * @param n    count
 */
void shell_sort(int list[], int n);

/**
 * @brief 합병 정렬 부속 함수(합병)
 * 
 * @param list int data array
 * @param left 
 * @param mid 
 * @param right 
 */
void merge(int list[], int left, int mid, int right);

/**
 * @brief 합병 정렬 | Time complexity: O(nlog2n)
 * 
 * @param list int data array
 * @param left 
 * @param right 
 */
void merge_sort(int list[], int left, int right);

/**
 * @brief 퀵 정렬 부속 함수(분할)
 * 
 * @param list int data array
 * @param left 
 * @param right 
 * @return int 
 */
int partition(int list[], int left, int right);

/**
 * @brief 퀵 정렬 | Time complexity: O(nlog2n)
 * 
 * @param list 
 * @param left 
 * @param right 
 */
void quick_sort(int list[], int left, int right);

#endif