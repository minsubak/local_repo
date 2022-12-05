/**
 * @file    union-find.h
 * @author  mindou (minsu5875@naver.com)
 * @brief   union-find 연산
 * 
 *          [개요]
 *          union연산은 입력받은 두 개의 매개변수의 합집합을 생성
 *          find연산 입력받은 매개변수의 루트 노드를 반환
 * 
 *          [동작 방식]
 *          parent_UF 배열을 set_init 함수를 이용해 루트노드로 초기화
 *          prrent_UF 배열에 저장된 값에 근거해 union-find 연산 수행         
 * 
 * @version null
 * @date    last update: 2022-12-05
 * 
 * @copyright Copyright (c) Mindou 2022
 * 
 */
#ifndef UNION_H
#define UNION_H

#include "main.h"

/**
 * @brief 부모 노드의 인덱스 저장 배열
 *        -1: 루트 노드(부모 노드가 없음)
 *         n: 부모 노드 주소값
 */
int parent_UF[MAX];

/**
 * @brief 보모 노드 배열 초기화
 * 
 * @param n 그래프 정점 개수
 */
void set_init(int n) {
    for (int i = 0; i < n; i++)
        parent_UF[i] = -1;
}

/**
 * @brief 현재 정점이 속하는 집합의 루트 노드 반환 | 
 *        배열에 저장된 값이 -1일 경우 루트 노드(반환),
 *        아닐 경우 해당 인덱스에 저장된 부모 노드로 계속 이동
 * 
 * @param curr 현재 정점 위치
 * @return int 
 */
int set_find(int curr) {
    if (parent_UF[curr] == -1)
        return curr;
    while(parent_UF[curr] != -1)
        curr = parent_UF[curr];
    return curr;
}

/**
 * @brief 입력받은 매개변수가 속한 집합의 합집합 생성
 *        , 만약 둘의 루트 노드가 같을 경우 생성하지 않는다
 * 
 * @param a 합집합 대상1
 * @param b 합집합 대상2
 */
void set_union(int a, int b) {
    int root1 = set_find(a);
    int root2 = set_find(b);
    if(root1 != root2)
        parent_UF[root1] = root2;
}

#endif