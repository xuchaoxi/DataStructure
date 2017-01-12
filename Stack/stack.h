/*************************************************************************
	> File Name: stack.h
	> Author: xu chaoxi
	> Mail: xuchaoxikb@gmail.com 
	> Created Time: Thu 12 Jan 2017 11:48:55 PM CST
 ************************************************************************/

#ifndef _STACK_H
#define _STACK_H
#endif

#include<iostream>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int ElemType;
typedef struct {
    ElemType *base;
    ElemType *top;
    int size;
}SqStack;

int InitStack(SqStack &S);

int DestroyStack(SqStack &S);

int ClearStack(SqStack &S);

int StackEmpty(SqStack S);

int StackLength(SqStack S);

int GetTop(SqStack S, ElemType &e);

int Push(SqStack &S, ElemType e);

int Pop(SqStack &S, ElemType &e);

int StackTraverse(SqStack S,void (*vi)(ElemType e));

