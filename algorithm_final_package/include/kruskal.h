#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "union-find.h"

/**
 * @brief 간선 구조체
 * 
 * @param start  출발 정점
 * @param end    도착 정점
 * @param weight 가중치
 */
struct Edge {
    int start, end, weight;
};

/**
 * @brief kruskal 그래프 구조체
 * 
 * @param n 간선 개수
 * @param v 정점 개수
 * @param edges
 */
typedef struct GraphType_K {
    int n, v;
    struct Edge edges[2*MAX];
}GraphType_K;

/**
 * @brief 그래프 초기화
 * 
 * @param g 그래프 구조체 포인터
 */
void init_graph_k(GraphType_K* g);

/**
 * @brief 그래프 간선 삽입
 * 
 * @param g     그래프 구조체 포인터
 * @param start 출발 정점
 * @param end   도착 정점
 * @param w     가중치
 */
void insert_edge_k(GraphType_K* g, int start, int end, int w);

/**
 * @brief qsort() 구성 요소
 * 
 * @param a 가중치 비교 대상1
 * @param b 가중치 비교 대상2
 * @return int 
 */
int  compare(const void* a, const void* b);

/**
 * @brief kruskal 알고리즘
 * 
 * @param g 그래프 구조체 포인터
 */
void kruskal(GraphType_K* g);

#endif