/**
 * @file    prim.h
 * @author  mindou (minsu5875@naver.com)
 * @brief   prim MST 알고리즘에 대한 설명
 *          
 *          [개요]
 *          입력받은 시작 정점에서부터 출발해 단계적으로 확장해나가는 알고리즘
 *          시작 단계에선 시작 정점만이 MST에 포함되며, 앞 단계에서 만들어진
 *          MST에서 인접한 정점들 중에서 가장 최저 간선으로 연결된 정점을 선택
 *          하여 트리를 확장하고 n-1개의 간선을 가질 때까지 지속
 * 
 *          [동작 방식]
 *          신장 트리 정점 집합에서 각 정점까지의 거리를 저장 하는 정점의 개수
 *          크기의 distance배열 이용, INF 값으로 초기화 후, 시작 정점을 0을, 
 *          추가되는 정점들이 트리집합에 추가되면서 값이 변경
 *          다음에 우선순위큐에 모든 정점을 삽입(우선순위는 distance 배열값)
 *          반복문을 이용 우선순위큐에서 가장 작은 distance값을 가진 정점 반환
 *          (get_min_vertex)하고 해당 정점이 트리 집합에 추가
 *          트리 집합에 새로운 정점 u가 추가되면 인접한 정점 v들의 distance값
 *          갱신(기존의 값보다 가중치 값이 적을 경우)
 *          이 과정을 큐에 있는 모든 정점이 소진될 때까지 반복하며 한 번 선택
 *          되어 큐에서 삭제된 정점과, 인접하지 않아 distance 값이 INF인 정점
 *          은 선택 불가
 * 
 * @version null
 * @date    last update: 2022-12-05
 * 
 * @copyright Copyright (c) Mindou 2022
 * 
 */
#ifndef PRIM_H
#define PRIM_H

#include "main.h"

bool selected_P[MAX];   // 배열형 우선순위큐
int  distance_P[MAX];   // 간선의 가중치 저장

/**
 * @brief prim 그래프 구조체
 * 
 * @param n      정점 개수
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
int get_min_vertex(int n) {
    int v;
    for(int i = 0; i < n; i++)
        if(!selected_P[i]) {
            v = i;
            break;
        }
    for(int i = 0; i < n; i++)
        if(!selected_P[i] && (distance_P[i] < distance_P[v])) v= i;
    return v;
}

/**
 * @brief prim 알고리즘
 * 
 * @param g 그래프 구조체 포인터
 * @param s 시작 정점
 */
void prim(GraphType_P* g, int s) {
    int u;
    for(u = 0; u < g->n; u++)           // distacne 배열 초기화
        distance_P[u] = INF;
    distance_P[s] = 0;                  // 시작 정점 초기화

    printf("prim MST algorithm\n");

    for(int i = 0; i < g->n; i++) {
        u = get_min_vertex(g->n);
        selected_P[u] = true;           // 큐에서 삭제
        if(distance_P[u] == INF) error("prim: weight error");
        printf("add vertex: %d\n", u);
        for(int v = 0; v < g->n; v++)   // 인접한 정점 v들의 distance값 갱신
            if(g->weight[u][v] != INF)
                if(!selected_P[v] && g->weight[u][v] < distance_P[v])
                    distance_P[v] = g->weight[u][v];
    }
}

/* // prim
int main() {
    GraphType_P g = { 7,
    {{ 0,  29, INF, INF, INF,  10, INF},
    { 29,   0,  16, INF, INF, INF,  15},
    {INF,  16,   0,  12, INF, INF, INF},
    {INF, INF,  12,   0,  22, INF,  18},
    {INF, INF, INF,  22,   0,  27,  25},
    { 10, INF, INF, INF,  27,   0, INF},
    {INF,  15, INF,  18,  25, INF,   0}}
    };
    prim(&g, 0);
    return 0;
}
*/

#endif