#include "main.h"

void execute_kruskal(); // kruskal 시연
void execute_prim();    // prim 시연
void execute_dijkstra();// dijkstra 시연
void execute_floyd();   // floyd 시연
void execute_topo();    // topo-sort 시연
void execute_sort();    // sort_package 시연

int arr[MAX/4];

int main() {

    FILE *fp = fopen("./res/data.txt", "r");
    if(fp == NULL) error("FIO: file not found!");
    
    int i = 0;
    while(!feof(fp)) {
        fscanf(fp, "%d", &arr[i++]);
    }

    while(true) {
        int input;
        printf(" |select algorithm list|\n0: exit\n1: MST\n2: shortest path\n3: topo-sort\n4: sort package\n>> ");
        scanf("%d", &input);
        if(input == 0) break;
        else {
            switch(input) {
            case 1:
                /**
                 * kruskal과 prim 둘 다 MST 알고리즘이지만
                 * kruskal은 간선, prim은 정점이 중심이다.
                 * 또 kruskal은 이전 단계의 결과에 상관 없이
                 * 무조건적으로 최저 간선을 선택해 확장하지만
                 * prim은 이전 단계의 결과에 따라 확장한다.
                */
                printf("MST\n\n");
                execute_kruskal();
                enter(1);
                execute_prim();
                break;
            case 2:
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
            case 3:
                printf("\n\ntopo-sort\n\n");
                execute_topo();
                break;
            case 4:
                execute_sort();
                break;
            default:
                printf("wrong answer\n");
                break;
            }
        }
    }
    printf("exit\n");
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

    GraphType_D g_dijkstra = {7, 
    {{ 0,   7, INF, INF,   3,  10, INF},
    {  7,   0,   4,  10,   2,   6, INF},
    {INF,   4,   0,   2, INF, INF, INF},
    {INF,  10,   2,   0,  11,   9,   4},
    {  3,   2, INF,  11,   0, INF,   5},
    { 10,   6, INF,   9, INF,   0, INF},
    {INF, INF, INF,   4,   5, INF,   0}}
    };

    dijkstra(&g_dijkstra, 0);
}

void execute_floyd() {
        
    GraphType_F g_floyd = {7, 
    {{ 0,   7, INF, INF,   3,  10, INF},
    {  7,   0,   4,  10,   2,   6, INF},
    {INF,   4,   0,   2, INF, INF, INF},
    {INF,  10,   2,   0,  11,   9,   4},
    {  3,   2, INF,  11,   0, INF,   5},
    { 10,   6, INF,   9, INF,   0, INF},
    {INF, INF, INF,   4,   5, INF,   0}}
    };

    floyd(&g_floyd);
}

void execute_topo() {
    GraphType_T g_topo;
    init_graph_t(&g_topo);
    insert_vertex(&g_topo, 0);
    insert_vertex(&g_topo, 1);
    insert_vertex(&g_topo, 2);
    insert_vertex(&g_topo, 3);
    insert_vertex(&g_topo, 4);
    insert_vertex(&g_topo, 5);

    // 정점 0의 인접 리스트 생성
    insert_edge_t(&g_topo, 0, 2);
    insert_edge_t(&g_topo, 0, 3);

    // 정점 1의 인접 리스트 생성
    insert_edge_t(&g_topo, 1, 3);
    insert_edge_t(&g_topo, 1, 4);

    // 정점 2의 인접 리스트 생성
    insert_edge_t(&g_topo, 2, 3);
    insert_edge_t(&g_topo, 2, 5);

    // 정점 3의 인접 리스트 생성
    insert_edge_t(&g_topo, 3, 5);

    // 정점 4의 인접 리스트 생성
    insert_edge_t(&g_topo, 4, 5);

    // 위상 정렬
    topo_sort(&g_topo);
}

void execute_sort() {

    int tmp[25];
    for(int i = 0; i < MAX/4; i++)
        tmp[i] = arr[i];

    printf("\n\n |select sort list|\n");
    printf("0: cancel\n1: selection\n2: insertion\n3: bubble\n4: shell\n5: merge\n6: quick\n7: radix\n>> ");
    int t;
    scanf("%d", &t);
    if(t == 0) return;
    switch(t) {
    case 1:
        printf("selection sort\n");
        selection_sort(tmp, MAX/4);
        for(int i = 0; i < MAX/4; i++)
            printf("%2d ", tmp[i]);
        enter(2);
        break;
    case 2:
        printf("insertion sort\n");
        insertion_sort(tmp, MAX/4);
        for(int i = 0; i < MAX/4; i++)
            printf("%2d ", tmp[i]);
        enter(2);
        break;
    case 3:
        printf("bubble sort\n");
        bubble_sort(tmp, MAX/4);
        for(int i = 0; i < MAX/4; i++)
            printf("%2d ", tmp[i]);
        enter(2);
        break;
    case 4:
        printf("shell sort\n");
        shell_sort(tmp, MAX/4);
        for(int i = 0; i < MAX/4; i++)
            printf("%2d ", tmp[i]);
        enter(2);
        break;
    case 5:
        printf("merge sort\n");
        merge_sort(tmp, 0,MAX/4);
        for(int i = 0; i < MAX/4; i++)
            printf("%2d ", tmp[i]);
        enter(2);
        break;
    case 6:
        printf("quick sort\n");
        quick_sort(tmp, 0, MAX/4);
        for(int i = 0; i < MAX/4; i++)
            printf("%2d ", tmp[i]);
        enter(2);
        break;
    case 7:
        printf("radix sort\n");
        radix_sort(tmp, MAX/4);
        for(int i = 0; i < MAX/4; i++)
            printf("%2d ", tmp[i]);
        enter(2);
        break;
    default: 
        printf("wrong answer\n");
        break;
    }
}

