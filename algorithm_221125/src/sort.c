#include "sort.h"
#include "queue.h"

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

int sorted[MAX/10]; // 합병 정렬을 위한 별도의 공간

void merge(int list[], int left, int mid, int right) {
    int i, j, k, l;
    i = left; j = mid + 1; k = left;
    /* 
       i: 정렬된 왼쪽 리스트에 대한 인덱스
       j: 정렬된 오른쪽 리스트에 대한 인덱스
       k: 정렬된 리스트에 대한 인덱스       */

    /* 분할 정렬된 list 합병 */
    while(i <= mid && j <= right) {
        if(list[i] <= list[j])
            sorted[k++] = list[i++];
        else 
            sorted[k++] = list[j++];
    }
    if(i < mid)     /* 남아있는 레코드 일괄 복사 */
        for(l = j; l <= right; l++)
            sorted[k++] = list[l];
    else            /* 남아있는 레코드 일괄 복사 */
        for(l = i; l <= mid; l++)
            sorted[k++] = list[l];
    /* 배열 sorted[]의 리스트를 비열 list[]로 재복사 */
    for(l = left; l <= right; l++)
        list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;   // list 균등 분할
        merge_sort(list, left, mid);    // 부분 list 정렬
        merge_sort(list, mid+1, right); // 부분 list 정렬
        merge(list, left, mid, right);  // 합병
    }
}

int partition(int list[], int left, int right) {
    int pivot, temp, low, high;

    low = left;
    high = right + 1;
    pivot = list[left];
    do {
        do
            low++;
        while(list[low] < pivot);
        do
            high--;
        while(list[high] > pivot);
        if(low < high) {
            temp = list[low];
            list[low] = list[high];
            list[high] = temp;
        }
    } while(low < high);
    temp = list[left];
    list[left] = list[high];
    list[high]= temp;
    return high;
}

void quick_sort(int list[], int left, int right) {
    if(left < right) {
        int q = partition(list, left, right);
        quick_sort(list, left, q - 1);
        quick_sort(list, q + 1, right);
    }
}

void radix_sort(int list[], int n) {
    QueueType q[BUCKETS];
    int factor = 1;

    for(int b = 0; b < BUCKETS; b++) init_queue(&q[b]);

    for(int d = 0; d < DIGITS; d++) {
        int i;
        for(i = 0; i < n; i++)
            enqueue(&q[(list[i]/factor)%10], list[i]);
        
        for(int b = 0; b < BUCKETS; b++)
            while(!is_empty(&q[b]))
                list[i++] = dequeue(&q[b]);
        factor *= 10;
    }
}