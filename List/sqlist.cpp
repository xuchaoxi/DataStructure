/*************************************************************************
	> File Name: sqlist.cpp
	> Author: xu chaoxi
	> Mail: xuchaoxikb@gmail.com 
	> Created Time: Tue 03 Jan 2017 02:56:43 PM CST
 ************************************************************************/

#include<stdio.h>
#include<iostream>
#include<malloc.h>
#include<stdlib.h>
#include"sqlist.h"
using namespace std;
int InitList_Sq(SqList &L)
{
    L.elem = (int *)malloc(SIZE * sizeof(int));
    if(!L.elem)exit(EXIT_FAILURE);
    L.length = 0;
    L.listsize = SIZE;
}

int DestroyList(SqList &L)
{
    free(L.elem);
    L.elem = NULL;
    L.length = 0;
    L.listsize = 0;
    return 1;
}

int ClearList(SqList &L)
{
    L.length = 0;
    return 1;

}

int ListEmpty(SqList L)
{
    if(L.length)return 0;
    else return 1;
}

int ListLength(SqList L)
{
    return L.length;
}

int GetElem(SqList L, int i, int &e)
{
    if(i < 1||i > L.length)
        exit(0);
    e = *(L.elem+i-1);
    return 1;
}
