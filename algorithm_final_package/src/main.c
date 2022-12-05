#include "main.h"

void execute_kruskal(); // kruskal 시연
void execute_prim();    // prim 시연
void execute_dijkstra();// dijkstra 시연
void execute_floyd();   // floyd 시연

int main() {

    printf("MST\n\n");
    /**
     * kruskal과 prim 둘 다 MST 알고리즘이지만
     * kruskal은 간선, prim은 정점이 중심이다.
     * 또 kruskal은 이전 단계의 결과에 상관 없이
     * 무조건적으로 최저 간선을 선택해 확장하지만
     * prim은 이전 단계의 결과에 따라 확장한다.
    */
    execute_kruskal();
    enter(1);
    execute_prim();

    /**
     * dijkstra와 floyd 모두 최단 경로 알고리즘이지만
     * dijkstra는 입력된 시작 정점에서 다른 정점까지의
     * 최단 경로를 구하고, floyd는 모든 정점에서 다른
     * 모든 정점까지의 최단 경로를 구한다는 차이가 있다.
    */
    printf("\n\nshortest path\n\n");
    execute_dijkstra();
    enter(1);
    execute_floyd();

    return 0;
}

void execute_kruskal() {

    GraphType_K *g_kruskal;
    g_kruskal = malloc(sizeof(GraphType_K));
    init_graph_k(g_kruskal);

    g_kruskal->v = 7;
    insert_edge_k(g_kruskal, 0, 1, 29);
    insert_edge_k(g_kruskal, 1, 2, 16);
    insert_edge_k(g_kruskal, 2, 3, 12);
    insert_edge_k(g_kruskal, 3, 4, 22);
    insert_edge_k(g_kruskal, 4, 5, 27);
    insert_edge_k(g_kruskal, 5, 0, 10);
    insert_edge_k(g_kruskal, 6, 1, 15);
    insert_edge_k(g_kruskal, 6, 3, 18);
    insert_edge_k(g_kruskal, 6, 4, 25);

    kruskal(g_kruskal);
    free(g_kruskal);
}

void execute_prim() {

    GraphType_P g_prim = { 7,
    {{ 0,  29, INF, INF, INF,  10, INF},
    { 29,   0,  16, INF, INF, INF,  15},
    {INF,  16,   0,  12, INF, INF, INF},
    {INF, INF,  12,   0,  22, INF,  18},
    {INF, INF, INF,  22,   0,  27,  25},
    { 10, INF, INF, INF,  27,   0, INF},
    {INF,  15, INF,  18,  25, INF,   0}}
    };

    prim(&g_prim, 0);
}

void execute_dijkstra(){

}

void execute_floyd() {
    
}