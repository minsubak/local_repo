/**
 * @file algorithm_221118_1.c
 * @author Mindou (minsu5875@naver.com)
 * @brief SCH algorithm lecture
 * @version null
 * @date 2022-11-18
 * 
 * @copyright Copyright by Mindou(c) 2022
 * g++ [filename.cpp] -o [filename] && ./[filename.exe]
 * 
 * data file
 * ryu 20174075 3
 * gun 20174022 1
 * lee 20174033 4
 * kim 20174015 2
 */
#include <stdio.h>
#include "algorithm_221118.h"

#pragma warning(disable : 4996)

int main() {
    FILE *fp = fopen("algorithm_221118_1_data.txt", "r");
    if(fp == NULL) error("file not found");

    student *s;
    int count = 0;
    while(!feof(fp)) {
        student tmp;
        fscanf(fp, "%s %d %d", tmp.name, &tmp.sID, &tmp.rank);
        count++;
    } rewind(fp);
    printf("count: %d\n", count);
    s = (student*)malloc(sizeof(student) * count);
    count = 0;
    while(!feof(fp)) {
        fscanf(fp, "%s %d %d", s[count].name, &s[count].sID, &s[count].rank);
        count++;
    }

    printf("before\n");
    print_s(s, count);

    printf("\n\nselection sort - rank\n");
    selection_sort(s, count);
    print_s(s, count);

    printf("\n\ninsertion sort - sID\n");
    selection_sort(s, count);
    print_s(s, count);

    printf("\n\n bubble sort   - name\n");
    bubble_sort(s, count);
    print_s(s, count);

    free(s);
    fclose(fp);

    return 0;
}