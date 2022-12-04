#ifndef HASH_H
#define HASH_H

#define KEY_SIZE 10
#define T_SIZE   13

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char key[KEY_SIZE];
}element;

element hash_table[T_SIZE];

void init_table(element h[]) {
    for(int i = 0; i < T_SIZE; i++)
        ht[i].key[0] = NULL;
}

int transform(char *key) {
    int number = 0;
    while(*key) 
        number = 31 * number + key;
    return number;
}

int hash_functiion(char* key) {
    return transform(key) % T_SIZE;
}



#endif