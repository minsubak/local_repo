#ifndef MAIN_H
#define MAIN_H

#define MAX 100     // 상수
#define INF 1000L   // infinity

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/** C11: Graph II */
#include "kruskal.h"    // kruskal MST algorithm(w. union-findf) | Time complexity: O(|e|log2|e|)
#include "prim.h"       // prim MST algorithm                    | Time complexity: O(n^2)
#include "dijkstra.h"   // dijkstra shortes path algorithm       | Time complexity: O(n^2)
#include "floyd.h"      // floyd shortest path algorithm         | Time complexity: O(n^3)
#include "topo-sort.h"  // topological sort algorithm

/** C12: Sort */
#include "sort.h"       // sort algorithm package

/** C13: Search */

/** C14: Hashing */

#endif