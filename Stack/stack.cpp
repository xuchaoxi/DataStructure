/*************************************************************************
	> File Name: stack.cpp
	> Author: xu chaoxi
	> Mail: xuchaoxikb@gmail.com 
	> Created Time: Fri 13 Jan 2017 12:11:35 AM CST
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include "stack.h"
using namespace std;

int InitStack(SqStack &S)
{
    S.base = (ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
    if(!S.base)exit(EXIT_FAILURE);
    S.top = S.base;
    S.size = STACK_INIT_SIZE;
    return 1;
}

int GetTop(SqStack S, ElemType &e)
{
    if(S.top == S.base)return 0;
    e = *(S.top-1);
    return 1;
}

int Push(SqStack &S, ElemType e)
{
    if(S.top - S.base >= S.size){
        S.base = (ElemType*)realloc(S.base, (S.size + STACKINCREMENT)*sizeof(ElemType));
        S.top = S.base + S.size;
        S.size = S.size + STACKINCREMENT;
    }
    *S.top++ = e;
    return 1;
}

int Pop(SqStack &S, ElemType &e)
{
    if(S.top == S.base)return 0;
    e = *--S.top;
    return 1;
}

int StackLength(SqStack S)
{
    return (S.top - S.base);
}

int StackEmpty(SqStack S)
{
    if(S.base == S.top)return 1;
    else return 0;
}

void visit(ElemType e)
{
    cout<<e<<" ";
}

int StackTraverse(SqStack S,void (*visit)(ElemType e))
{
    if(S.base == S.top)return 0;
    ElemType e;
    while(!StackEmpty(S))
    {
        Pop(S,e);
        visit(e);
    }
    cout<<endl;
    return 1;
}


