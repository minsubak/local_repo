/**
 * @file    topo-sort.h
 * @author  mindou (minsu5875@naver.com)
 * @brief   topological sort algorithm에 대한 설명
 *          
 *          [개요]
 *          방향 그래프에 존재하는 각 정점들의 선행 순서를 위배하지 않으면서 모
 *          든 정점을 나열하는 것 방향 그래프의 위상 정렬
 *          진입 차수가 0인 정점을 선택하고, 선택된 정점과 여기에 부착된 모든
 *          간선을 삭제를 하는 과정을 반복해 모든 정점이 선택 및 삭제되면 알고
 *          리즘 종료
 *          진입 차수가 0인 정점이 여럿이 존재할 경우 어느 정점을 선택해도 무방
 *          그래프에 남아 있는 정점 중에 진입 차수 0인 정점이 없을 경우, 실행
 *          불가능한 프로젝트가 되고 알고리즘 중단
 * 
 *          [동작 방식]
 *          1차원 배열 in_degree를 만들고 각 정점의 진입 차수를 기록하고 배열값
 *          이 0인 후보 정점들은 스택에 푸시
 *          이후 스택에서 하나 씩 꺼내 출력하면서 그래프에서 제거되고, 인접한 정
 *          점들의 배열값을 1만큼 감소하고 그에 따라 배열값이 0이 된 후보 정점들
 *          을 다시 스택에 푸시하는 과정을 전체 정점을 출력할 때까지 지속
 *          만약 전체 정점이 출력되지 않을 경우, 그래프에 사이클이 존재해 위상
 *          쩡렬 순서가 존재하지 않은 것
 * 
 * @version null
 * @date    last update: 2022-12-06
 * 
 * @copyright Copyright (c) Mindou 2022
 * 
 */
#ifndef TOPO_H
#define TOPO_H

#include "stack.h"
#include "main.h"

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
 * @brief 위상 정렬 그래프 초기화
 * 
 * @param g 그래프 구조체 포인터
 */
void init_graph_t(GraphType_T* g) {
    g->n = 0;
    for(int v = 0; v < MAX/2; v++)
        g->adj_list[v] = NULL;
}

/**
 * @brief 정점 삽입
 * 
 * @param g 그래프 구조체 포인터
 * @param v 추가할 정점
 */
void insert_vertex(GraphType_T* g, int v) {
    if(((g->n) + 1) > MAX/2)
        error("topo-sort: number of vertex is exceed");
    g->n++;
}

/**
 * @brief 간선 삽입
 * 
 * @param g 그래프 구조체 포인터
 * @param u 정점 u
 * @param v 정점 v
 */
void insert_edge_t(GraphType_T* g, int u, int v) {
    if(u >= g->n || v >= g->n)
        error("topo-sort: vertex number error");
    GraphNode *node = malloc(sizeof(GraphNode));
    node->v = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

/**
 * @brief 위상정렬 알고리즘
 * 
 * @param g 그래프 구조체 포인터
 * @return int 
 */
int topo_sort(GraphType_T* g) {
    int i;
    StackType s;
    GraphNode *node;

    /* 모든 정점의 진입 차수 계산 */
    int *in_degree = malloc(sizeof(int)*g->n);  // 진입 차수 저장 배열
    for(i = 0; i < g->n; i++)                   // 배열 초기화
        in_degree[i] = 0;
    for(i = 0; i < g->n; i++) {
        node = g->adj_list[i];                  // 정점 i에서 나오는 간선들
        while(node != NULL) {
            in_degree[node->v]++;
            node = node->link;
        }
    }
    /* 진입 차수 0인 정점 스택 푸시 */
    init_stack(&s);
    for(i = 0; i < g->n; i++) {
        if(in_degree[i] == 0) push(&s, i);
    }
    /* 위상 순서를 생성 */
    while(!is_empty_s(&s)) {
        int w = pop(&s);                        // 진입 차수 0인 정점 팝
        printf("vertex %d -> ", w);             // 팝한 정점 출력
        node = g->adj_list[w];                  // 각 정점의 진입 차수 변경
        while(node != NULL) {
            int u = node->v;
            in_degree[u]--;                     // 배열에 저장된 해당 정점 진입 차수 감소
            if(in_degree[u] == 0) push(&s, u);  // 진입 차수가 감소되 0이 될 경우 스택 푸시
            node = node->link;                  // 다음 정점으로 이동
        }
    }
    free(in_degree);
    printf("\n");
    return (i == g->n);
}

/* //topo-sort
int main() {
    GraphType_T g;
    graph_init_t(&g);
    insert_vertex(&g, 0);
    insert_vertex(&g, 1);
    insert_vertex(&g, 2);
    insert_vertex(&g, 3);
    insert_vertex(&g, 4);
    insert_vertex(&g, 5);

    // 정점 0의 인접 리스트 생성
    insert_edge_t(&g, 0, 2);
    insert_edge_t(&g, 0, 3);

    // 정점 1의 인접 리스트 생성
    insert_edge_t(&g, 1, 3);
    insert_edge_t(&g, 1, 4);

    // 정점 2의 인접 리스트 생성
    insert_edge_t(&g, 2, 3);
    insert_edge_t(&g, 2, 5);

    // 정점 3의 인접 리스트 생성
    insert_edge_t(&g, 3, 5);

    // 정점 4의 인접 리스트 생성
    insert_edge_t(&g, 4, 5);

    // 위상 정렬
    topo_sort(&g);
    return 0;
}
*/

#endif