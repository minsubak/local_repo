/**
 * @file algorithm_221118_2.c
 * @author Mindou (minsu5875@naver.com)
 * @brief SCH algorithm lecture
 * @version null
 * @date 2022-11-18
 * 
 * @copyright Copyright by Mindou(c) 2022
 * 
 */

#include <stdio.h>
#include "algorithm_221118_practice.h"

#pragma warning (disable:4996)

int main() {
    FILE *fp = fopen("algorithm_221118_2_data.txt", "r");
    if(fp == NULL) error("file not found");

    element *list;
    int count = 0;
    while(!feof(fp)) {
        element tmp;
        fscanf(fp, "%s %d %s", tmp.name, &tmp.ID, &tmp.cellphone);
        count++;
    } rewind(fp);
    list = (element*)malloc(sizeof(element) * count);
    count = 0;
    while(!feof(fp)) {
        fscanf(fp, "%s %d %s", list[count].name, &list[count].ID, &list[count].cellphone);
        count++;
    }

    printf("before\n");
    print_e(list, count);

    printf("\n\nshell sort\n");
    shell_sort(list, count);
    print_e(list, count);

    free(list);
    fclose(fp);
    return 0;
}