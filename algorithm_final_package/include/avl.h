/**
 * @file    avl.h
 * @author  mindou (minsu5875@naver.com)
 * @brief   AVL 트리에 대한 설명
 * 
 *          [개요]
 *          각 노드에서 왼쪽 서브트리의 높이와 오른쪽 서브트리 의 높이 차이가
 *          1 이하인 이진 탐색트리
 *          트리가 불균형 상태가 되면 스스로 노드를 재배치해 균형 상태로 복구
 *          AVL트리는 균형 트리가 항상 보장, 항상 O(logn)시간 안에 탐색 종료
 * 
 * @version null
 * @date    last update: 2022-12-06
 * 
 * @copyright Copyright (c) Mindou 2022
 * 
 */
#ifndef AVL_H
#define AVL_H

#include "main.h"

/**
 * @brief avl binary tree linked list
 * 
 */
typedef struct AVLNode {
    int key;
    struct AVLNode *left, *right;
}AVLNode;

/**
 * @brief avl 트리를 오른쪽으로 회전시키는 함수
 * 
 * @param p root
 * @return AVLNode* 
 */
AVLNode* rotate_right(AVLNode* p) {
    AVLNode* c = p->left;
    p->left = c->right;
    c->right = p;
    return c;   // 새 루트 반환
}

/**
 * @brief avl 트리를 왼쪽으로 회전시키는 함수
 * 
 * @param p root
 * @return AVLNode* 
 */
AVLNode* rotate_left(AVLNode* p) {
    AVLNode* c = p->right;
    p->right = c->left;
    c->left = p;
    return c;   // 새 루트 반환
}

int max(int a, int b) {
    if(a > b) return a;
    else return b;
}

/**
 * @brief Get the height AVL tree
 * 
 * @param node 
 * @return int 
 */
int get_height(AVLNode* node) {
    int h = 0;
    if(node != NULL)
        h = 1 + max(get_height(node->left), get_height(node->right));
    return h;
}

int get_balance(AVLNode* node) {
    if(node == NULL) return 0;
    return get_height(node->left)-get_height(node->right);
}

AVLNode* create_node(int key) {
    AVLNode* node = malloc(sizeof(AVLNode));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

AVLNode* insert(AVLNode* node, int key) {
    if(node == NULL)
        return(create_node(key));
    
    if(key < node->key)
        node->left = insert(node->left, key);
    else if(key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    
    /** avl tree의 균형인수 재계산 */
    int balance = get_balance(node);

    /** LL */
    if(balance > 1 && key < node->left->key)
        return rotate_right(node);

    /** RR */
    if(balance < -1 && key > node->right->key)
        return rotate_left(node);

    /** LR */
    if(balance > 1 && key > node->left->key)
        return rotate_right(node);

    /** RL */
    if(balance < -1 && key < node->right->key)
        return rotate_left(node);
    
    return node;
}

void preorder(AVLNode* root) {  // 전위 순회
    if(root != NULL) {
        printf("[%d]", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

#endif