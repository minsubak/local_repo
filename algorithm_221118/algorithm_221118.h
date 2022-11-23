/**
 * @file    algorithm_221118.h
 * @author  박민수-20194013(Mindou) (minsu5875@naver.com)
 * @brief   알고리즘 실습 12주차 과제 헤더파일
 * @version not exist
 * @date    update: 2022-11-21 (info: add commit and opstimization)
 * 
 * @copyright Copyright by Mindou (c) 2022
 * 
 */
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 에러 메세지 출력
 * 
 * @param message error info
 */
void error(char *message);

/**
 * @brief 선택 정렬
 * 
 * @param list int data array
 * @param n    count
 */
void selection_sort(int list[], int n);

/**
 * @brief 삽입 정렬
 * 
 * @param list int data array
 * @param n    count
 */
void insertion_sort(int list[], int n);

/**
 * @brief 버블 정렬
 * 
 * @param list int data array
 * @param n    count
 */
void bubble_sort(int list[], int n);

/**
 * @brief 쉘 정렬의 부속 함수(삽입)
 * 
 * @param list  int data array
 * @param first first sort pos
 * @param last  last sort pos
 * @param gap   gap of first and last
 */
void inc_insertion_sort(int list[], int first, int last, int gap);

/**
 * @brief 쉘 정렬
 * 
 * @param list int data array
 * @param n    count
 */
void shell_sort(int list[], int n);

/**
 * @brief 배열 초기화 함수 | 배열 내용을 정렬 전의 초기 형태로 초기화
 * 
 * @param list   int data array
 * @param target reset target
 * @param n      count
 */
void reset_array(int list[], int target[], int n);

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void selection_sort(int list[], int n) {
    int tmp;
    for(int i = 0; i < n; i++) {
        int min = 1;
        for(int j = i + 1; j < n; j++) {
            if(list[j] < list[min])
                min = j;
        }
        tmp = list[i];
        list[i] = list[min];
        list[min] = tmp;
    }
}

void insertion_sort(int list[], int n) {
    int j, tmp;
    for (int i = 0; i < n; i++) {
        tmp = list[i];
        for(j = i - 1; j >= 0 && list[j] > tmp; j--)
            list[j + 1] = list[j];
        list[j+1] = tmp;
    }
}

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

void inc_insertion_sort(int list[], int first, int last, int gap){
    int j;
    int key;
    for(int i = first+gap; i <= last; i = i+gap) {
        key = list[i];
        for(j = i - gap; j >= first && key < list[j]; j= j-gap)
            list[j+gap] = list[j];
        list[j+gap] = key;
    }
}

void shell_sort(int list[], int n){
    for(int gap = n/2; gap > 0; gap = gap/2) {
        if((gap % 2) == 0) gap++;
        for(int i = 0; i < gap; i++) {
            inc_insertion_sort(list, i, n-1, gap);
    }}
}

void reset_array(int list[], int target[], int n) {
    for(int i = 0; i < n; i++)
        target[i] = list[i];
}
#endif