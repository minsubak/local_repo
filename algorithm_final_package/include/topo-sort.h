#ifndef TOPO_H
#define TOPO_H

#include "stack.h"

/**
 * @brief 그래프 노드
 * 
 * @param v     정점
 * @param link  다음 노드를 가리키는 링크
 */
typedef struct GraphNode {
    int v;
    struct GraphNode *link;
}GraphNode;

/**
 * @brief 위상 정렬 그래프 구조체
 * 
 * @param n        정점 개수
 * @param adj_list 노드 데이터
 */
typedef struct GraphType_T {
    int n;
    GraphNode *adj_list[MAX/2];
}GraphType_T;

/**
 * @brief 그래프 초기화
 * 
 * @param g 그래프 구조체 포인터
 */
void init_graph_t(GraphType_T* g);

/**
 * @brief 정점 삽입
 * 
 * @param g 그래프 구조체 포인터
 * @param v 추가할 정점
 */
void insert_vertex(GraphType_T* g, int v);

/**
 * @brief 간선 삽입
 * 
 * @param g 그래프 구조체 포인터
 * @param u 정점 u
 * @param v 정점 v
 */
void insert_edge_t(GraphType_T* g, int u, int v);

/**
 * @brief 위상정렬 알고리즘
 * 
 * @param g 그래프 구조체 포인터
 * @return int 
 */
int  topo_sort(GraphType_T* g);

#endif