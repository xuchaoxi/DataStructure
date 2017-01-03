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
    L.elem = (ElemType *)malloc(SIZE * sizeof(ElemType));
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

int GetElem(SqList L, int i, ElemType &e)
{
    if(i < 1||i > L.length)
        exit(0);
    e = *(L.elem+i-1);
    return 1;
}

int LocateElem(SqList L, ElemType e, int (*compare)(ElemType, ElemType))
{
    ElemType *p = L.elem;
    int i = 1;
    while(i <= L.length && !compare(e, *p++))
        i++;
    if(i <= L.length)
        return i;
    else
        return 0;
}

int compare(ElemType e1, ElemType e2)
{
    if(e1==e2)return 1;
    else return 0;
}

int ListInsert(SqList &L, int i, ElemType e)
{
    ElemType *newbase, *p, *q;
    int k = 0;
    if(i < 1 || i > L.length+1)return 0;
    if(L.length >= L.listsize)
    {
        newbase = (ElemType *)realloc(L.elem, (L.length+INCREMENT)*sizeof(ElemType));
        if(!newbase)return 0;
        L.elem = newbase;
        L.listsize = L.length+INCREMENT;
    }
    q = L.elem + i-1; //q为插入位置 q=&(L.elem[i-1])
    for(p = L.elem+L.length-1; p >= q; p--)
        *(p+1) = *p;
    *q = e; //插入e
    L.length++;
    return 1;

}

int ListDelete(SqList &L, int i, ElemType &e)
{
    ElemType  *q;
    q = L.elem + i-1;  //删除的位置
    e = *q;
    for(++q ; q <= L.elem+L.length-1; q++)
        *(q-1) = q;
    L.length--;
    return 1;
}






