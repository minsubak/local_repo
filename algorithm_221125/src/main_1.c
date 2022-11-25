#include <stdio.h>
#include "sort.h"
//radix sort
int main() {
    FILE *fp = fopen("data_radix.txt", "r");
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
    radix_sort(list, count);

    for(int i = 0; i < count; i++)
        printf("%d ", list[i]);
    printf("\n");

    free(list);
    fclose(fp);
    return 0;
}