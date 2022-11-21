/**
 * @file    algorithm_221118_report.c
 * @author  박민수-20194013(Mindou) (minsu5875@naver.com)
 * @brief   알고리즘 실습 12주차 과제
 *          (IDE: vscode, Compiler: mingw)
 *          만약 vscode와 msys2(mingw) 이용할 경우 해당 커맨드를 터미널에 입력해 실행
 *          : g++ algorithm_221118_report.c -o reprot && ./report
 * @version not exist
 * @date    update: 2022-11-21 (info: add commit and opstimization)
 * 
 * @copyright Copyright by Mindou (c) 2022
 * 
 */
#include <time.h>
#include "algorithm_221118.h"           // 정렬 알고리즘 및 기타 함수 헤더

#define MAX 10000                       // 정수 1만개 정의

int arr[MAX];                           // 랜덤정수 1만개를 저장할 원형배열
int main() {

    srand((unsigned int)time(NULL));    // 랜덤함수 시드 기준 -> 시간
    
    for(int i = 0; i < MAX; i++)        // arr 배열 랜덤정수 생성 및 삽입
        arr[i] = rand() % MAX;
    
    clock_t start, end;                                              

    int tmp[MAX];                       // 정렬 알고리즘에 사용될 배열

    reset_array(arr, tmp, MAX);         // tmp 배열을 arr 배열 내용으로 초기화
    printf("selection sort\n");
    start = clock();                    // 시간 측정 시작
    selection_sort(tmp, MAX);           // 선택 정렬
    end = clock();                      // 시간 측정 종료
    printf("ms: %d\n", end - start);

    reset_array(arr, tmp, MAX);         // tmp 배열을 arr 배열 내용으로 초기화
    printf("insertion sort\n");
    start = clock();                    // 시간 측정 시작
    insertion_sort(tmp, MAX);           // 삽입 정렬
    end = clock();                      // 시간 측정 종료
    printf("ms: %d\n", end - start);

    reset_array(arr, tmp, MAX);         // tmp 배열을 arr 배열 내용으로 초기화
    printf("bubble sort\n");            
    start = clock();                    // 시간 측정 시작
    bubble_sort(tmp, MAX);              // 버블 정렬
    end = clock();                      // 시간 측정 종료
    printf("ms: %d\n", end - start);

    reset_array(arr, tmp, MAX);         // tmp 배열을 arr 배열 내용으로 초기화
    printf("shell sort\n");
    start = clock();                    // 시간 측정 시작
    shell_sort(tmp, MAX);               // 쉘 정렬
    end = clock();                      // 시간 측정 종료
    printf("ms: %d\n", end - start);

    return 0;
}