#ifndef PRACTICE_H
#define PRACTICE_H

#include <stdio.h>
#include <stdlib.h>
//

/**
 * @brief studnet info struct
 * 
 */
typedef struct student{
    char name[20];
    int  sID;
    int  rank;
}student;

typedef struct element {
    char name[20];
    int  ID;
    char cellphone[20];
}element;

/**
 * @brief print int array data
 * 
 * @param list int data
 * @param n    count
 */
void print_s(int list[], int n);

/**
 * @brief print int array data
 * 
 * @param list int data
 * @param n    count
 */
void print_e(int list[], int n);

/**
 * @brief print error message
 * 
 * @param message error info
 */
void error(char *message);

/**
 * @brief using selection sort
 * 
 * @param list int data
 * @param n    count
 */
void selection_sort(int list[], int n);

/**
 * @brief using insertion sort
 * 
 * @param list int data
 * @param n    count
 */
void insertion_sort(int list[], int n);

/**
 * @brief using bubble sort
 * 
 * @param list int data
 * @param n    count
 */
void bubble_sort(int list[], int n);

/**
 * @brief componenet of shell sort
 * 
 * @param list  data
 * @param first first sort pos
 * @param last  last sort pos
 * @param gap   gap of first and last
 */
void inc_insertion_sort(int list[], int first, int last, int gap);

/**
 * @brief using shell sort
 * 
 * @param list data
 * @param n    count
 */
void shell_sort(int list[], int n);

void print_s(student s[], int n) {
    for(int i = 0; i < n; i ++) {
        printf("%s %d %d\n", s[i].name, s[i].sID, s[i].rank);
    }
}

void print_e(element list[], int n) {
        for(int i = 0; i < n; i ++) {
        printf("%s %d %s\n", list[i].name, list[i].ID, list[i].cellphone);
    }
}

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