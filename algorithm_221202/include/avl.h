#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxs(a, b) a>b?a:b

typedef struct {
    char word[100];
    char mean[100];
}element;

typedef struct AvlNode {
    element data;
    struct AvlNode *left, *right;
}AvlNode;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}
AvlNode *avl_insert(AvlNode **root, element new_key) {

    /** fail to search == insert pos */
    if(*root == NULL) {

        *root = malloc(sizeof(AvlNode));
        if(*root = NULL) error("malloc failure");

        /** initallizing */
        (*root)->data = new_key;
        (*root)->left = (*root)->right = NULL;


    } else if(strcmp(new_key.word, (*root)->data.word) > 0) {

        (*root)->left = avl_insert(&((*root)->left), new_key);
        (*root) = rebalance(root);  // AVL tree balance check

    } else if(strcmp(new_key.word, (*root)->data.word) < 0) {

        (*root)->right = avl_insert(&((*root)->right), new_key);
        (*root) = rebalance(root);  //AVL tree balance check

    } else {

        /** overlap */
        error("key overlap error");
    }
}

AvlNode* rotate_LL(AvlNode *parent) {

    AvlNode *child = parent->left;
    parent->left = child->right;
    child->right = parent;

    return child;
}

AvlNode* rotate_RR(AvlNode *parent) {
    AvlNode *child = parent->right;
    parent->right = child->left;
    child->left = parent;

    return child;
}

AvlNode* rotate_RL(AvlNode *parent) {
    AvlNode *child = parent->right;
    parent->right =  rotate_LL(child);

    return rotate_RR(parent);
}

AvlNode* rotate_LR(AvlNode *parent) {
    AvlNode *child = parent->left;
    parent->left =  rotate_RR(child);

    return rotate_LL(parent);
}

AvlNode *rebalance(AvlNode **node) {

    int height_diff = get_height_diff(*node);

    if(height_diff > 1) {  

        /** left serve tree is longer */
        if(get_height_diff((*node)->left > 0))
            *node = rotate_LL(*node);
        else
            *node = rotate_LR(*node);
        
    } else if(height_diff < -1) {
        
        /** right serve tree is longer */
        if(get_height_diff((*node)->right < 0))
            *node = rotate_RR(*node);
        else
            *node = rotate_RL(*node);
    }
}

AvlNode *avl_serach(AvlNode *node, element key) {

    if(node == NULL) return NULL;

    if(strcmp(key.word, node->data.word) == 0)
        return node;

    else if(strcmp(key.word, node->data.word) > 0)
        return avl_serach(node->left, key);

    else if(strcmp(key.word, node->data.word) < 0)
        return avl_serach(node->right, key);
}

int get_height(AvlNode* node) {
    int height = 0;
    
    if(node != NULL) {
        height = 1 + maxs(get_height(node->left), get_height(node->right));
    }
    return height;
}

int get_height_diff(AvlNode** node) {

    if((*node) == NULL)
        return 0;

    return get_height((*node)->left) - get_height((*node)->right);
}

#endif