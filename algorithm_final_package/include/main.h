#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100     // constant
#define INF 1000L   // infinity

/** 
 * MST: 그래프 내 모든 정점을 포함 및 연결되있어야 하며 사이클을 포함하지 않는 트리가 신장 트리이다.
 * 그중 MST(최소 비용 신장 트리)는 각 정점들의 간선의 개수와 가중치의 총합이 최소값인 신장 트리를 뜻한다.
 */

/** 
 * shortest path: 네트워크에서 정점 i와 정점 j를 연결하는 경로 중에서 간선들의 가중치 합이 최소가 되는
 * 경로를 찾는 문제이다(MST와 달리 모든 노드의 연결이 필요치 않다).
*/

/** C11: Graph II */
#include "kruskal.h"    // kruskal MST algorithm(w. union-find)  | Time complexity: O(|e|log2|e|)
#include "prim.h"       // prim MST algorithm                    | Time complexity: O(|e|log2|e|) ~ O(n^2)
#include "dijkstra.h"   // dijkstra shortest path algorithm      | Time complexity: O(n^2)
//#include "floyd.h"      // floyd shortest path algorithm         | Time complexity: O(n^3)
//#include "topo-sort.h"  // topological sort algorithm
#include "union-find.h" // use with "kruskal.h"

/** C12: Sort */
//#include "sort.h"       // sort algorithm package

/** C13: Search */


/** C14: Hashing */

/**
 * @brief print error message and exit program
 * 
 * @param message error info
 */
void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

/**
 * @brief print newline
 * 
 * @param n count
 */
void enter(int n) {
    for(int i = 0; i < n; i++)
        printf("\n");
}

#endif