// hash
#include "hash.h"

int main() {
    element e;
    char cmd[100];
    char name[100];

    while(1) {
        printf("insert(i), search(s), quit(q)");
        scanf("%s", cmd);

        if(strcmp(cmd "i") == 0) {
            printf("animal name: ");
            scanf("%s, name");strcpy(e.key, name);
            
        }
    }
;}

// avl
/* #include "avl.h"

int main() {

    FILE *fp = fopen("data.txt", "r");
    if(fp==NULL) {error("file not found");}

    char flag;
    element tmp;
    AvlNode *A;

    while(!feof(fp)) {
        fscanf(fp, "%c", &flag);

        if(flag == 'i') {
            fscanf(fp, "%s %s", tmp.word, tmp.mean);
            printf("insert: %s %s\n", tmp.word, tmp.mean);
            avl_insert(&A, tmp);
        }

        if(flag == 's') {
            fscanf(fp, "%s", &tmp.word);

            printf("search: %s\n", tmp.word);
            strcpy(tmp.mean, "");
            A = avl_serach(A, tmp);
            printf("word: %s / mean: %s\n", A->data.word, A->data.mean);
        }
    }

    //printf("\n\ntree print\n");
    //display();

    return 0;
} */