/**
 * @file    kruskal.h
 * @author  mindou (minsu5875@naver.com)
 * @brief   kurskal MST 알고리즘에 대한 설명
 * 
 *          [개요]
 *          탐욕적인 방법(greedly method)을 이용해 선택의 순간마다 가장 좋다고
 *          생각하는(ex: 최소 비용 간선을 선택) 것을 선택하는 알고리즘
 *          kruskal은 MST가 최소 비용의 간선으로 구성됨과 동시에 사이클을 포함
 *          하지 않는다는 조건에 근거하여, 각 단계에서 사이클을 이루지 않는 최소
 *          비용 간선을 선택
 *          
 *          [동작 방식]
 *          먼저 그래프의 간선들의 가중치를 오름차순으로 정렬, 정렬된 간선들의
 *          리스트에서 사이클을 형성하지 않는 간선을 찾아서 현재의 MST의 집합에
 *          추가, 만약 사이클을 형성할 경우 제외
 *          간선이 집합에 추가될 때, 사이클 확인을 위해 union-find 연산을 사용
 *          union(x, y)는 입력받은 매개변수 x, y가 속한 집합을 입력으로 받아
 *          2개의 집합의 합집합을 만들고, find(x)는 매개변수 x가 속해있는 집합
 *          을 반환
 *          집합 구현에 여러가지 방법이 사용 가능하나, 트리 형태가 가장 효율적
 *          포인터 없이 1차원 배열로 구현 가능하며 각 노드의 부모에 대한 포인터
 *          만 저장하는 "부모 포인터 표현"을 사용해 "두 노드가 같은 트리에 존재
 *          하나"?에 필요한 정보를 받아와 배열에 부모 노드의 인덱스를 저장
 * 
 * @version null
 * @date    last update: 2022-12-05
 * 
 * @copyright Copyright (c) Mindou 2022
 * 
 */
#ifndef KRUSKAL_H
#define KRUSKAL_H

/** kruskal의 사이클 체크 */
#include "union-find.h"
#include "main.h"

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
 * @param n     간선 개수
 * @param v     정점 개수
 * @param edges 간선 데이터
 */
typedef struct GraphType_K {
    int n, v;
    struct Edge edges[2*MAX];
}GraphType_K;

/**
 * @brief kruskal 그래프 초기화
 * 
 * @param g 그래프 구조체 포인터
 */
void init_graph_k(GraphType_K* g) {
    g->n = g->v = 0;
    for(int i = 0; i < 2 * MAX; i++) {
        g->edges[i].start  = 0;
        g->edges[i].end    = 0;
        g->edges[i].weight = INF;
    }
}

/**
 * @brief 그래프 간선 삽입
 * 
 * @param g     그래프 구조체 포인터
 * @param start 출발 정점
 * @param end   도착 정점
 * @param w     가중치
 */
void insert_edge_k(GraphType_K* g, int start, int end, int w) {
    g->edges[g->n].start  = start;
    g->edges[g->n].end    = end;
    g->edges[g->n].weight = w;
    g->n++;
}

/**
 * @brief qsort() 구성 요소
 * 
 * @param a 가중치 비교 대상1
 * @param b 가중치 비교 대상2
 * @return int 
 */
int compare(const void* a, const void* b) {
    struct Edge* x = (struct Edge*)a;
    struct Edge* y = (struct Edge*)b;
    return (x->weight - y->weight);
}

/**
 * @brief kruskal 알고리즘
 * 
 * @param g 그래프 구조체 포인터
 */
void kruskal(GraphType_K* g) {
    int uset, vset;         // 정점 u, v의 집합 번호
    int edge_accepted = 0;  // 집합에 포함된 간선 개수
    struct Edge e;

    set_init(g->v);         // 집합 초기화
    qsort(g->edges, g->n, sizeof(struct Edge), compare);

    printf("kruskal MST algorithm\n");

    int i = 0;
    while(edge_accepted < (g->v - 1)) {
        e = g->edges[i];
        uset = set_find(e.start);   // 정점 u 집합 번호
        vset = set_find(e.end);     // 정점 v 집합 번호

        if(uset != vset) {          // 서로 속한 집합이 다를 경우
            printf("edge (%d, %d) weight: %d selected\n", e.start, e.end, e.weight);
            edge_accepted++;
            set_union(uset, vset);  // 두 집합의 합집합 생성
        }
        i++;
    }
}

/*  //kruskal
int main() {
    GraphType_K *g;
    g = malloc(sizeof(GraphType_K));
    init_graph_k(g);

    g->v = 7;
    insert_edge_k(g, 0, 1, 29);
    insert_edge_k(g, 1, 2, 16);
    insert_edge_k(g, 2, 3, 12);
    insert_edge_k(g, 3, 4, 22);
    insert_edge_k(g, 4, 5, 27);
    insert_edge_k(g, 5, 0, 10);
    insert_edge_k(g, 6, 1, 15);
    insert_edge_k(g, 6, 3, 18);
    insert_edge_k(g, 6, 4, 25);

    kruskal(g);
    free(g);
    return 0;
}
*/

#endif