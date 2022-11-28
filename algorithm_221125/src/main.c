#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
//quick sort
int main() {
    FILE *fp = fopen("data_quick.txt", "r");
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

/* #include <stdio.h>
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
} */


/* #include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
//seq_search
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
    
    int *list = malloc(count * (sizeof(int)));

    count = 0;
    while(!feof(fp)) {
        fscanf(fp, "%d", &list[count]);
        count++;
    }

    int key;
    printf("key: ");
    scanf("%d", &key);

    clock_t start, end;
    start = clock();
    int result = seq_search(list, key, 0, count-1);
    end = clock();
    printf("seq_search: %dms \tindex: %d\n", end-start, result);

    start = clock();
    result = better_seq_search(list, key, 0, count-1);
    end = clock();
    printf("better_seq_search: %dms \tindex: %d\n", end-start, result);

    return 0;
} */