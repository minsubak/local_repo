#ifndef UNION_H
#define UNION_H

#include "main.h"

int parent[MAX];  // 부모 노드

/**
 * @brief 보모 노드 초기화
 * 
 * @param n 정점 개수
 */
void set_init(int n);

/**
 * @brief 현재 정점이 속하는 집합 반환
 * 
 * @param curr 현재 정점
 * @return int 
 */
int  set_find(int curr);

/**
 * @brief 합집합
 * 
 * @param a 합집합 대상1
 * @param b 합집합 대상2
 */
void set_union(int a, int b);

#endif