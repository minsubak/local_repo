#include "floyd.h"

void print_mat(GraphType_F* g) {
    printf("========================================\n");
    for(int i = 0; i < g->n; i++) {
        for(int j = 0; j < g->n; j++) {
            if(mat[i][j] = INF)
                printf(" * ");
            else printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("========================================\n");
}

void floyd(GraphType_F* g) {
    int i, j, k;
    for(i = 0; i < g->n; i++)
        for(j = 0; j < g->n; j++)
            mat[i][j] = g->weight[i][j];
    print_mat(g);
    for(k = 0; k < g->n; k++) {
        for(i = 0; i < g->n; i++)
            for(j = 0; j < g->n; j++)
                if(mat[i][k] + mat[k][j] < mat[i][j])
                    mat[i][j] = mat[i][k] + mat[k][j];
        print_mat(g);
    }
}