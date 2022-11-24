#ifndef PRIM_H
#define PRIM_H

#include "main.h"

int selected_P[MAX];    // 선택된 노드 저장
int distance_P[MAX];    // 간선의 가중치 저장

/**
 * @brief prim 그래프 구조체
 * 
 * @param n 정점 개수
 * @param weight 가중치 배열
 */
typedef struct GraphType_P{
    int n;
    int weight[MAX][MAX];
}GraphType_P;

/**
 * @brief distance_P[v]의 최솟값을 갖는 정점 리턴
 * 
 * @param n 정점 개수
 * @return int 
 */
int  get_min_v(int n);

/**
 * @brief prim 알고리즘
 * 
 * @param g 그래프 구조체 포인터
 * @param s 시작 정점
 */
void prim(GraphType_P* g, int s);

#endif