#include "kruskal.h"
#include <stdlib.h>

void init_graph_k(GraphType_K* g) {
    g->n = g->v = 0;
    for(int i = 0; i < 2 * MAX; i++) {
        g->edges[i].start  = 0;
        g->edges[i].end    = 0;
        g->edges[i].weight = INF;
    }
}

void insert_edge_k(GraphType_K* g, int start, int end, int w) {
    g->edges[g->n].start  = start;
    g->edges[g->n].end    = end;
    g->edges[g->n].weight = w;
    g->n++;
}

int compare(const void* a, const void* b) {
    struct Edge* x = (struct Edge*)a;
    struct Edge* y = (struct Edge*)b;
    return (x->weight - y->weight);
}

void kruskal(GraphType_K *g) {
    int uset, vset;         // 정점 u, v의 집합 번호
    int edge_accepted = 0;  // 선택된 간선 개수
    struct Edge e;

    set_init(g->v);         // 집합 초기화
    qsort(g->edges, g->n, sizeof(struct Edge), compare);

    printf("kruskal MST algorithm\n");

    int i = 0;
    while(edge_accepted < (g->v - 1)) {
        e = g->edges[i];
        uset = set_find(e.start);   // 정점 u 집합 번호
        vset = set_find(e.end);     // 정점 v 집합 번호

        if(uset != vset) {          // 서로 속한 집합이 다를 경우
            printf("edge (%d, %d) %d selected\n", e.start, e.end, e.weight);
            edge_accepted++;
            set_union(uset, vset);  // 합집합
        }
        i++;
    }
}

/*  //kruskal
int main() {
    GraphType_K *g;
    g = malloc(sizeof(GraphType_K));
    init_graph_k(g);

    g->v = 7;
    insert_edge_k(g, 0, 1, 29);
    insert_edge_k(g, 1, 2, 16);
    insert_edge_k(g, 2, 3, 12);
    insert_edge_k(g, 3, 4, 22);
    insert_edge_k(g, 4, 5, 27);
    insert_edge_k(g, 5, 0, 10);
    insert_edge_k(g, 6, 1, 15);
    insert_edge_k(g, 6, 3, 18);
    insert_edge_k(g, 6, 4, 25);

    kruskal(g);
    free(g);
    return 0;
}
*/