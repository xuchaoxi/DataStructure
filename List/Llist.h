/*************************************************************************
	> File Name: Llist.h
	> Author: xu chaoxi
	> Mail: xuchaoxikb@gmail.com 
	> Created Time: Thu 12 Jan 2017 11:02:23 PM CST
 ************************************************************************/

#ifndef _LLIST_H
#define _LLIST_H
#endif

#include<iostream>
using namespace std;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

int GetElem_L(LinkList L, int i, ElemType &e);

int ListInsert_L(LinkList &L, int i, ElemType e);

int ListDelete_L(LinkList &L, int i, ElemType &e);

void CreateList_L(LinkList &L, int n);





