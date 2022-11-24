#include "prim.h"

int get_min_v(int n) {
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

void prim(GraphType_P* g, int s) {
    int u;
    for(u = 0; u < g->n; u++)
        distance_P[u] = INF;
    distance_P[s] = 0;
    for(int i = 0; i < g->n; i++) {
        u = get_min_v(g->n);
        selected_P[u] = true;
        if(distance_P[u] == INF) return;
        printf("add vertex %d", u);
        for(int v = 0; v < g->n; v++)
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