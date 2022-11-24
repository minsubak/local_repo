#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "main.h"

int distance_D[MAX];  // 시작 정점으로부터의 최단 경로 거리
int visited_D[MAX];   // 방문한 정점

/**
 * @brief dijkstra 그래프 구조체
 * 
 * @param n 정점 개수
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
int  choose(int distance_D[], int n, int visited_D[]);

/**
 * @brief 그래프 상태 출력
 * 
 * @param g 그래프 구조체 포인터
 */
void print_status(GraphType_D* g);

/**
 * @brief dijkstra 알고리즘
 * 
 * @param g     그래프 구조체 포인터
 * @param start 시작 정점
 */
void dijkstra(GraphType_D* g, int start);

#endif