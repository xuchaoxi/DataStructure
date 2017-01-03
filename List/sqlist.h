/*************************************************************************
	> File Name: SqList.h
	> Author: xu chaoxi
	> Mail: xuchaoxikb@gmail.com 
	> Created Time: Tue 03 Jan 2017 02:43:46 PM CST
 ************************************************************************/

#ifndef _SqList_H
#define _SqList_H
#endif
#include<stdio.h>
#include<iostream>
#define SIZE 100    //线性表初始存储分配量
#define INCREMENT 10    //存储增量
using namespace std;
typedef int ElemType;
typedef struct{
    ElemType *elem;      //存储空间基址
    int length;     //当前长度
    int listsize;   //分配长度
}SqList;
//构造一个空的线性表mZ
//重置为空表
int ClearList(SqList &L);
//判断是否为空表
int ListEmpty(SqList L);
//返回元素个数
int ListLength(SqList L);
//返回第i个元素
int GetElem(SqList L, int i, ElemType &e);
//元素定位
int LocateElem(SqList L,ElemType e, int (*compare)(ElemType, ElemType));
//前驱
int PriorElem(SqList L, ElemType cur_e, ElemType &pre_e);
//后继
int NextElem(SqList L, ElemType cur_e, ElemType &next_e);
//插入元素e
int ListInsert(SqList &L, int i, ElemType e);
//删除第i个元素
int ListDelete(SqList &L, int i, ElemType &e);
//遍历线性表
int ListTraverse(SqList L, void (*visit)(ElemType *));
//比较函数
int compare(ElemType e1, ElemType e2);
//输出函数
void print(ElemType *e);

