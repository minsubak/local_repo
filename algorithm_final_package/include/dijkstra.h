/**
 * @file    dijkstra.h
 * @author  mindou (minsu5875@naver.com)
 * @brief   dijkstra shortest path 알고리즘에 대한 설명
 * 
 *          [개요]
 *          네트워크에서 입력된 시작 정점부터 다른 정점까지의 최단 경로를 찾는
 *          알고리즘 최단경로는 경로의 길이 순으로 정렬
 * 
 *          [동작 방식]
 *          
 * 
 * @version null
 * @date    2022-12-05
 * 
 * @copyright Copyright (c) Mindou 2022
 * 
 */
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "main.h"

int distance_D[MAX];  // 시작 정점부터의 최단경로
int visited_D[MAX];   // 방문한 정점

/**
 * @brief dijkstra 그래프 구조체
 * 
 * @param n      정점 개수
 * @param weight 가중치 배열
 */
typedef struct GraphType_D {
    int n;
    int weight[MAX][MAX];
}GraphType_D;

/**
 * @brief dijkstar 구성 요소
 * 
 * @param distance_D 시작 정점으로부터의 최단 경로 거리
 * @param n          정점 개수
 * @param visited_D  방문한 정점
 * @return int 
 */
int choose(int distance_D[], int n, int visited_D[]) {
    int i, min, minpos;
    min = INT_MAX;
    minpos = -1;
    for(i = 0; i < n; i++)
        if(distance_D[i] < min && !visited_D[i]) {
            min = distance_D[i];
            minpos = i;
        }
}

/**
 * @brief 그래프 상태 출력
 * 
 * @param g 그래프 구조체 포인터
 */
void print_status(GraphType_D *g) {
    static int step = 1;
    printf("STEP  %d: ", step++);
    printf("distance: ");
    for(int i = 0; i < g->n; i++) {
        if(distance_D[i] == INF)
            printf(" * ");
        else
            printf("%2d", distance_D[i]);
    }
    printf("\n");
    printf(" visited: ");
    for(int i = 0; i < g->n; i++)
        printf("%2d", visited_D[i]);
    printf("\n\n");
}

/**
 * @brief dijkstra 알고리즘
 * 
 * @param g     그래프 구조체 포인터
 * @param start 시작 정점
 */
void dijkstra(GraphType_D* g, int start) {
    for(int i = 0; i < g->n; i++) { // 초기화
        distance_D[i] = g->weight[start][i];
        visited_D[i] = false;
    }
    visited_D[start] = true;    // 시작 정점 방문
    distance_D[start] = 0;
    for(int i = 0; i < g->n; i++) {
        print_status(g);
        int u = choose(distance_D, g->n, visited_D);
        visited_D[u] = true;
        for(int w = 0; w < g->n; w++)
            if(!visited_D[w])
                if(distance_D[u] + g->weight[u][w] < distance_D[w])
                    distance_D[w] = distance_D[u] + g->weight[u][w];
    }
}

/* // dijkstra
int main() {
    GraphType g = {7, 
    {{ 0,   7, INF, INF,   3,  10, INF},
    {  7,   0,   4,  10,   2,   6, INF},
    {INF,   4,   0,   2, INF, INF, INF},
    {INF,  10,   2,   0,  11,   9,   4},
    {  3,   2, INF,  11,   0, INF,   5},
    { 10,   6, INF,   9, INF,   0, INF},
    {INF, INF, INF,   4,   5, INF,   0}}
    };
}
*/

#endif