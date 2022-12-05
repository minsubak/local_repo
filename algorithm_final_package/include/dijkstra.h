/**
 * @file    dijkstra.h
 * @author  mindou (minsu5875@naver.com)
 * @brief   dijkstra shortest path algorithm에 대한 설명
 * 
 *          [개요]
 *          네트워크에서 입력된 시작 정점부터 다른 정점까지의 최단 경로를 찾는
 *          알고리즘, 최단경로는 경로의 길이 순으로 정렬
 * 
 *          [동작 방식]
 *          집합S를 시작정점v로부터의 최단경로가 발견된 정점들의 집합이라 가정
 *          dijkstra 알고리즘은 집합S에 있는 정점만을 거쳐 다른 정점으로 가는 
 *          최단경로를 기록하는 distance배열이 필요
 *          시작단계에선 최단경로가 발견된 정점이 없지만 알고리즘이 진행되면서
 *          최단경로가 발견되는 정점들이 S에 하나씩 추가
 *          알고리즘의 각 단계에서 S안에 존재하지 않는 정점 중에 distance값이
 *          가장 작은 정점 S에 추가되고, S에 있지 않는 정점들의 distance값을
 *          갱신(distance[w] = min(distance[w], distance[u]+weight[u][w]))
 *          최단경로는 알 수 있지만, 별도의 자료구조없이 경로 파악 불가
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
bool visited_D[MAX];  // 방문한 정점

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
 * @brief distance배열에서 최솟값을 가진 인덱스 반환
 * 
 * @param distance_D 시작 정점으로부터의 최단경로 배열
 * @param n          정점 개수
 * @param visited_D  방문한 정점
 * @return int 
 */
int choose(int distance_D[], int n, bool visited_D[]) {
    int min = INF;  // 최단경로 값
    int minpos = -1;    // 최단경로 값 인덱스
    for(int i = 0; i < n; i++)
        /** distance배열에서 가장 작은 값이면서 방문하지 않은 인덱스 반환 */
        if(distance_D[i] < min && !visited_D[i]) {
            min = distance_D[i];
            minpos = i;
        }
    return minpos;
}

/**
 * @brief 그래프 상태 출력
 * 
 * @param g 그래프 구조체 포인터
 */
void print_status(GraphType_D *g) {
    static int step = 1;
    printf("\nSTEP  %d: \n", step++);
    printf("distance: ");
    for(int i = 0; i < g->n; i++) {
        if(distance_D[i] == INF)
            printf(" * ");
        else
            printf("%2d ", distance_D[i]);
    }
    printf("\n");
    printf(" visited: ");
    for(int i = 0; i < g->n; i++)
        printf("%2d ", visited_D[i]);
    printf("\n");
}

/**
 * @brief dijkstra 알고리즘
 * 
 * @param g     그래프 구조체 포인터
 * @param start 시작 정점
 */
void dijkstra(GraphType_D* g, int start) {
    for(int i = 0; i < g->n; i++) {     // 초기화
        distance_D[i] = g->weight[start][i];
        visited_D[i] = false;
    }
    visited_D[start] = true;            // 시작 정점 방문 처리
    distance_D[start] = 0;              // 시작 정점 거리값 설정

    printf("dijkstra shortest path algorithm");

    for(int i = 0; i < g->n; i++) {
        print_status(g);
        int u = choose(distance_D, g->n, visited_D);    // distance배열의 최솟값 인덱스 반환
        visited_D[u] = true;            // 해당 정점 방문 처리
        for(int w = 0; w < g->n; w++)   // 추가된 정점을 기준으로 distance배열 값 갱신
            if(!visited_D[w])           // w노드를 방문하지 않은 경우
                if(distance_D[u] + g->weight[u][w] < distance_D[w]) // 최솟값으로 변경
                    distance_D[w] = distance_D[u] + g->weight[u][w];
    }
}

/* // dijkstra
int main() {
    GraphType_D g = {7, 
    {{ 0,   7, INF, INF,   3,  10, INF},
    {  7,   0,   4,  10,   2,   6, INF},
    {INF,   4,   0,   2, INF, INF, INF},
    {INF,  10,   2,   0,  11,   9,   4},
    {  3,   2, INF,  11,   0, INF,   5},
    { 10,   6, INF,   9, INF,   0, INF},
    {INF, INF, INF,   4,   5, INF,   0}}
    };
    dijkstra(&g, 0);
    return 0;
}
*/

#endif