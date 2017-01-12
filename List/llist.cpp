/*************************************************************************
	> File Name: Llist.cpp
	> Author: xu chaoxi
	> Mail: xuchaoxikb@gmail.com 
	> Created Time: Thu 12 Jan 2017 11:07:38 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include "Llist.h"
using namespace std;

int GetElem_L(LinkList L, int i, ElemType &e)
{
    LinkList p = L->next;
    for(int k = 1; p && k < i; k++)
        p = p->next;
    if(!p || k > i)return 0;
    e = p->data;
    return 1;
}

int ListInsert_L(LinkList &L, int i, ElemType e)
{
    LinkList p = L;
    int j = 0;
    while(p && j < i-1) {
        p = p->next;
        j++;
    }
    if(!p || j > i-1) return 0;
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}

int ListDelete_L(LinkList &L, int i, ElemType &e)
{
    LinkList p = L;
    int j = 0;
    while(p && j < i-1){
        p = p->next;
        j++;
    }
    if(!p || j > i-1)return 0;
    LinkList q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return 1;

}

void CreateList_L(LinkList &L, int n)
{
    L = (LinkList)malloc(sizeof(Lnode));
    L->next = NULL;
    LinkList p;
    for(int i = 0;i < n;i++)
    {
        p = (LinkList)malloc(sizeof(LNode));
        cin>>p->data;
        p->next = L->next;
        L-next = p;
    }
}


