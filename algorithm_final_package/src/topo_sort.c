#include "topo-sort.h"

void init_graph_t(GraphType_T* g) {
    g->n = 0;
    for(int v = 0; v < MAX; v++)
        g->adj_list[v] = NULL;
}

void insert_vertex(GraphType_T* g, int v) {
    if(((g->n) + 1) > MAX) {
        fprintf(stderr, "GRAPH: number of vertex is exceed\n");
        return;
    }
    g->n++;
}

void insert_edge_t(GraphType_T* g, int u, int v) {
    if(u >= g->n || v >= g->n) {
        fprintf(stderr, "GRAPH: vertex number error\n");
        return;
    }
    GraphNode *node = malloc(sizeof(GraphNode));
    node->v = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

int  topo_sort(GraphType_T* g) {
    int i;
    StackType s;
    GraphNode *node;

    // 모든 정점의 진입 차수 계산
    int *in_degree = malloc(sizeof(int)*g->n);
    for(i = 0; i < g->n; i++)   // 초기화
        in_degree[i] = 0;
    for(i = 0; i < g->n; i++) {
        node = g->adj_list[i];  // 정점 i에서 나오는 간선들
        while(node != NULL) {
            in_degree[node->v]++;
            node = node->link;
        }
    }
    // 진입 차수가 0인 정점을 스택에 삽입
    init_stack(&s);
    for(i = 0; i < g->n; i++) {
        if(in_degree[i] == 0) push(&s, i);
    }
    //위상 순서를 생성
    while(!is_empty(&s)) {
        int w;
        w = pop(&s);
        printf("vertex %d -> ", w); // 정점 출력
        node = g->adj_list[w];      // 각 정점의 진입 차수 변경ㄴ
        while(node != NULL) {
            int u = node->v;
            in_degree[u]--;         // 정점 진입 차수 감소
            if(in_degree[u] == 0) push(&s, u);
            node = node->link;      // 다음 정점
        }
    }
    free(in_degree);
    printf("\n");
    return (i == g->n);
}

/* //topo-sort
int main() {
    GraphType g;
    graph_init_t(&g);
    insert_vertex(&g, 0);
    insert_vertex(&g, 1);
    insert_vertex(&g, 2);
    insert_vertex(&g, 3);
    insert_vertex(&g, 4);
    insert_vertex(&g, 5);

    // 정점 0의 인접 리스트 생성
    insert_edge_t(&g, 0, 2);
    insert_edge_t(&g, 0, 3);

    // 정점 1의 인접 리스트 생성
    insert_edge_t(&g, 1, 3);
    insert_edge_t(&g, 1, 4);

    // 정점 2의 인접 리스트 생성
    insert_edge_t(&g, 2, 3);
    insert_edge_t(&g, 2, 5);

    // 정점 3의 인접 리스트 생성
    insert_edge_t(&g, 3, 5);

    // 정점 4의 인접 리스트 생성
    insert_edge_t(&g, 4, 5);

    // 위상 정렬
    topo_sort(&g);
    return 0;
}
*/