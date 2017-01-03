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
typedef struct{
    int *elem;      //存储空间基址
    int length;     //当前长度
    int listsize;   //分配长度
}SqList;
//构造一个空的线性表
int InitList_Sq(SqList &L);
//销毁线性表
int DestroyList(SqList &L);
//重置为空表
int ClearList(SqList &L);
//判断是否为空表
int ListEmpty(SqList L);
//返回元素个数
int ListLength(SqList L);
//返回第i个元素
int GetElem(SqList L, int i, int &e);







