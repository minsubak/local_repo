/**
 * @file    stack.h
 * @author  mindou (minsu5875@naver.com)
 * @brief   stack 자료구조
 *          
 *          [개요]
 *          기본 스택 자료 구조
 * 
 * @version null
 * @date    last update: 2022-12-06
 * 
 * @copyright Copyright (c) Mindou 2022
 * 
 */
#ifndef STACK_H
#define STACK_H

#include "main.h"

typedef int element_s;
/**
 * @brief 스택
 * 
 * @param stack 스택
 * @param top 현재 스택 저장 사이즈
 */
typedef struct {
    element_s stack[MAX];
    int top;
}StackType;

/**
 * @brief 스택 초기화
 * 
 * @param s 스택 구조체 포인터
 */
void init_stack(StackType* s) {
    s->top = -1;
}

/**
 * @brief 스택 검사 - empty
 * 
 * @param s 스택 구조체 포인터
 * @return int 
 */
int is_empty_s(StackType *s) {
    return (s->top == -1);
}

/**
 * @brief 스택 검사 - full
 * 
 * @param s 스택 구조체 포인터
 * @return int 
 */
int  is_full_s(StackType *s) {
    return (s->top == (MAX - 1));
}

/**
 * @brief 스택 추가
 * 
 * @param s 스택 구조체 포인터
 * @param item 추가할 요소
 */
void push(StackType *s, element_s item) {
    if(is_full_s(s)) {
        error("stack: stack is full");
    } else s->stack[++(s->top)] = item;
}

/**
 * @brief 스택 감소
 * 
 * @param s 스택 구조체 포인터
 * @return element 
 */
element_s pop(StackType *s) {
    if(is_empty_s(s)) {
        error("stack: stack is empty");
    } else return s->stack[(s->top)--];
}

#endif