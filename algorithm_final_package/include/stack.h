#ifndef STACK_H
#define STACK_H

#include "main.h"

typedef int element;
/**
 * @brief 스택
 * 
 * @param stack 스택
 * @param top 현재 스택 저장 사이즈
 */
typedef struct {
    element stack[MAX];
    int top;
}StackType;

/**
 * @brief 스택 초기화
 * 
 * @param s 스택 구조체 포인터
 */
void init_stack(StackType* s);

/**
 * @brief 스택 검사 - empty
 * 
 * @param s 스택 구조체 포인터
 * @return int 
 */
int  is_empty(StackType *s);

/**
 * @brief 스택 검사 - full
 * 
 * @param s 스택 구조체 포인터
 * @return int 
 */
int  is_full(StackType *s);

/**
 * @brief 스택 추가
 * 
 * @param s 스택 구조체 포인터
 * @param item 추가할 요소
 */
void push(StackType *s, element item);

/**
 * @brief 스택 감소
 * 
 * @param s 스택 구조체 포인터
 * @return element 
 */
element pop(StackType *s);

void init_stack(StackType* s) {
    s->top = -1;
}

int  is_empty(StackType *s) {
    return (s->top == -1);
}

int  is_full(StackType *s) {
    return (s->top == (MAX - 1));
}

void push(StackType *s, element item) {
    if(is_full(s)) {
        fprintf(stderr, "stack is full\n");
        return;
    } else s->stack[++(s->top)] = item;
}

element pop(StackType *s) {
    if(is_empty(s)) {
        fprintf(stderr,"stack is empty\n");
        exit(1);
    } else return s->stack[(s->top)--];
}

#endif