#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100     // constant
#define INF 1000L   // infinity

#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

/** 
 * MST: 그래프 내 모든 정점을 포함 및 연결되있어야 하며 사이클을 포함하지 않는 트리가 신장 트리이다.
 * 그중 MST(최소 비용 신장 트리)는 각 정점들의 간선의 개수와 가중치의 총합이 최소값인 신장 트리를 뜻한다.
 */

/** 
 * shortest path: 네트워크에서 정점 i와 정점 j를 연결하는 경로 중에서 간선들의 가중치 합이 최소가 되는
 * 경로를 찾는 문제이다(MST와 달리 모든 노드의 연결이 필요치 않다).
*/

/** C11: Graph II */
#include "kruskal.h"            // Time complexity: O(|e|log2|e|)          | kruskal MST algorithm(w. union-find)
#include "prim.h"               // Time complexity: O(|e|log2|e|) ~ O(n^2) | prim MST algorithm
#include "dijkstra.h"           // Time complexity: O(n^2)                 | dijkstra shortest path algorithm
#include "floyd.h"              // Time complexity: O(n^3)                 | floyd shortest path algorithm
#include "topo-sort.h"          //                                         | topological sort algorithm
#include "union-find.h"         //                                         | use with "kruskal.h"
#include "stack.h"              //                                         | use with "topo-sort.h"

/** C12: Sort */
#include "selection_sort.h"     // Time complexity: O(n^2)                 |
#include "insertion_sort.h"     // Time complexity: O(n^2)                 |
#include "bubble_sort.h"        // Time complexity: O(n^2)                 |
#include "shell_sort.h"         // Time complexity: O(n^1.5) ~ O(n^2)      |
#include "merge_sort.h"         // Time complexity: O(nlog2n)              |
#include "quick_sort.h"         // Time complexity: O(nlog2n)              |
#include "radix_sort.h"         // Time complexity: O(d*n) ~ o(n)          |
#include "queue.h"              // use with "radix_sort.h"                 |

/** C13: Search */
#include "seq_search.h"         // Time complexity: O(n)                   | use with "index_seq_search.h"
#include "binary_search.h"      // Time complexity: O(log2n)
#include "index_seq_search.h"   // Time complexity: O(m+n/m)
#include "interpol_search.h"    // Time complexity: O(log2n)
#include "avl.h"                // Time complexity: O(logn)

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