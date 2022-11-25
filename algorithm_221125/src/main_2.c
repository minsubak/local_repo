#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"

#pragma warning (disable : 4996)

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
    }
    rewind(fp);

    printf("data count: %d\n", count);
    
    int *list = (int*)malloc(count * (sizeof(int)));

    count = 0;
    while(!feof(fp)) {
        fscanf(fp, "%d", list[count]);
        count++;
    }

    int key;
    printf("key: ");
    scanf("%d", &key);

    clock_t start, end;
    start = clock();
    seq_search(list, key, 0, count-1);
    end = clock();
    printf("seq_search: %dms", end-start);

    start = clock();
    better_seq_search(list, key, 0, count-1);
    end = clock();
    printf("better_seq_search: %dms", end-start);

    return 0;
}