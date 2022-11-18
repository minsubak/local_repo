#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algorithm_221118.h"

#define MAX 10000

int arr[MAX];
int main() {

    srand((unsigned int)time(NULL));
    for(int i = 0; i < MAX; i++) {
        arr[i] = rand() % 10000;
    }
    clock_t start, end;
    int tmp[MAX];

    reset_array(arr, tmp, MAX);
    printf("selection sort\n");
    start = clock();
    selection_sort(tmp, MAX);
    end = clock();
    printf("ms: %d\n", end - start);

    reset_array(arr, tmp, MAX);
    printf("insertion sort\n");
    start = clock();
    insertion_sort(tmp, MAX);
    end = clock();
    printf("ms: %d\n", end - start);

    reset_array(arr, tmp, MAX);
    printf("bubble sort\n");
    start = clock();
    bubble_sort(tmp, MAX);
    end = clock();
    printf("ms: %d\n", end - start);

    reset_array(arr, tmp, MAX);
    printf("shell sort\n");
    start = clock();
    shell_sort(tmp, MAX);
    end = clock();
    printf("ms: %d\n", end - start);

    return 0;
}