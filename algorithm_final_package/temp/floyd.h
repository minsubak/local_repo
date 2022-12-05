#ifndef FLOYD_H
#define FLOYD_H

#include "main.h"

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
void print_mat(GraphType_F* g);

/**
 * @brief floyd 알고리즘
 * 
 * @param g 그래프 구조체 포인터
 */
void floyd(GraphType_F* g);

#endif