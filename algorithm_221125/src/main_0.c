#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
//quick sort
int main() {
    FILE *fp = fopen("data.txt", "r");
    if(fp == NULL) {
        fprintf(stderr, "file not found!\n");
        exit(1);
    }

    int temp, count = 0;
    while(!feof(fp)) {
        fscanf(fp, "%d", &temp);
        count++;
    } rewind(fp);

    int *list = (int*)malloc(sizeof(int) * count);

    count = 0;
    while(!feof(fp)) {
        fscanf(fp, "%d", &list[count]);
        count++;
    }

    quick_sort(list, 0, count - 1);

    for(int i = 0; i < count; i++)
        printf("%d ", list[i]);
    printf("\n");

    free(list);
    fclose(fp);
    return 0;
}