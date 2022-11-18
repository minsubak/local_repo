#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief studnet info struct
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
 * @brief print error message
 * 
 * @param message error info
 */
void error(char *message);

/**
 * @brief print student array data
 * 
 * @param s student data
 * @param n count
 */
void print_s(student s[], int n);

/**
 * @brief print element array data
 * 
 * @param list element data
 * @param n    count
 */
void print_e(element list[], int n);

/**
 * @brief using selection sort
 * 
 * @param s student data
 * @param n count
 */
void selection_sort(student s[], int n);

/**
 * @brief using insertion sort
 * 
 * @param s studnet data
 * @param n count
 */
void insertion_sort(student s[], int n);

/**
 * @brief using bubble sort
 * 
 * @param s student data
 * @param n count
 */
void bubble_sort(student s[], int n);

/**
 * @brief componenet of shell sort
 * 
 * @param list  data
 * @param first first sort pos
 * @param last  last sort pos
 * @param gap   gap of first and last
 */
void inc_insertion_sort(element list[], int first, int last, int gap);

/**
 * @brief using shell sort
 * 
 * @param list data
 * @param n    count
 */
void shell_sort(element list[], int n);

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

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

void selection_sort(student s[], int n) {
    student tmp;
    for(int i = 0; i < n; i++) {
        int min = 1;
        for(int j = i + 1; j < n; j++) {
            if(s[j].rank < s[min].rank)
                min = j;
        }
        tmp = s[i];
        s[i] = s[min];
        s[min] = tmp;
    }
}

void insertion_sort(student s[], int n) {
    int j;
    student tmp;
    for (int i = 0; i < n; i++) {
        tmp = s[i];
        for(j = i - 1; j >= 0 && s[i].sID > tmp.sID; j--)
            s[j + 1] = s[j];
        s[j+1] = tmp;
    }
}

void bubble_sort(student s[], int n) {
    student tmp;
    for(int i = n - 1; i> 0; i--) {
        for(int j = 0; j < i; j++) {
            if(strcmp(s[j].name, s[j+1].name) > 0) {
                tmp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = tmp;
            }
        }
    }
}

void inc_insertion_sort(element list[], int first, int last, int gap){
    int j;
    element key;
    for(int i = first+gap; i <= last; i = i+gap) {
        key = list[i];
        for(j = i - gap; j >= first && key.ID < list[i].ID; j= j-gap)
            list[j+gap] = list[j];
        list[j+gap] = key;
    }
}

void shell_sort(element list[], int n){
    for(int gap = n/2; gap > 0; gap = gap/2) {
        if((gap % 2) == 0) gap++;
        for(int i = 0; i < gap; i++)
            inc_insertion_sort(list, i, n-1, gap);
    }
}
#endif