/**
 * @file    floyd.h
 * @author  mindou (minsu5875@naver.com)
 * @brief   floyd shortest path algorithm에 대한 설명
 *          
 *          [개요]
 *          그래프에 존재하는 모든 정점 사이의 최단 경로를 한 번에 모두 찾아주
 *          는 알고리즘 2차원 배열을 이용해 3중 반복문을 사용하는 루프로 구성
 *          되어 간단명료
 *          floyd의 핵심 내용은 0부터 n-1까지의 모든 정점을 이용해 최단 거리를
 *          구하는 최단경로 알고리즘
 * 
 *          [동작 방식]
 *          인접 행렬 weight가 존재할 때, i==j일 경우 0을, 두개의 정점 i, j의
 *          간선이 존재하지 않는 경우 INF라 하고, i, j의 간선이 존재하는 경우
 *          weight[i][j]는 해당 간선의 가중치를 저장
 *          3중 반복문에 사용되는 2차원 배열의 초기값은 가중치 행렬
 * 
 * @version null
 * @date    last update: 2022-12-05
 * 
 * @copyright Copyright (c) Mindou 2022
 * 
 */
#ifndef FLOYD_H
#define FLOYD_H

#include "main.h"

/** floyd 연산을 위한 행렬 */
int mat[MAX][MAX];

/**
 * @brief floyd 그래프 구조체
 * 
 * @param n 정점 개수
 * @param weight 가중치 배열
 */
typedef struct GraphType_F {
    int n;
    int weight[MAX][MAX];
}GraphType_F;

/**
 * @brief mat 매트릭스 출력
 * 
 * @param g 그래프 구조체 포인터
 */
void print_mat(GraphType_F* g) {
    printf("=====================\n");
    for(int i = 0; i < g->n; i++) {
        for(int j = 0; j < g->n; j++) {
            if(mat[i][j] == INF)
                printf(" * ");
            else printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief floyd 알고리즘
 * 
 * @param g 그래프 구조체 포인터
 */
void floyd(GraphType_F* g) {
    for(int i = 0; i < g->n; i++)           // mat행렬 초기화
        for(int j = 0; j < g->n; j++)
            mat[i][j] = g->weight[i][j];
    printf("floyd shortest path algorithm\n");
    print_mat(g);
    for(int k = 0; k < g->n; k++) {
        for(int i = 0; i < g->n; i++)
            for(int j = 0; j < g->n; j++)
                if(mat[i][k] + mat[k][j] < mat[i][j])
                    mat[i][j] = mat[i][k] + mat[k][j];
        print_mat(g);
    }
    printf("=====================\n");
}
/* // floyd
int main() {
    GraphType_F g = {7, 
    {{ 0,   7, INF, INF,   3,  10, INF},
    {  7,   0,   4,  10,   2,   6, INF},
    {INF,   4,   0,   2, INF, INF, INF},
    {INF,  10,   2,   0,  11,   9,   4},
    {  3,   2, INF,  11,   0, INF,   5},
    { 10,   6, INF,   9, INF,   0, INF},
    {INF, INF, INF,   4,   5, INF,   0}}
    };
    floyd(&g);
    return 0;
}
*/
#endif