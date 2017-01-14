/*************************************************************************
	> File Name: squeue.cpp
	> Author: xu chaoxi
	> Mail: xuchaoxikb@gmail.com 
	> Created Time: Sat 14 Jan 2017 10:21:20 AM CST
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include "queue.h"
using namespace std;

int InitQueue(SqQueue &Q)
{
    Q.base = (QElemType*)malloc(MAXQSIZE*sizeof(QElemType));
    if(!Q.base) exit(EXIT_FAILURE);
    Q.front = Q.rear = 0;
    return 1;
}

int QueueLength_Sq(SqQueue Q)
{
    return (Q.rear - Q.front + MAXQSIZE)%MAXQSIZE;
}

int EnQueue_Sq(SqQueue &Q, QElemType e)
{
    if((Q.rear+1)%MAXQSIZE == Q.front) return 0;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1)%MAXQSIZE;
    return 1;
}

int DeQueue_Sq(SqQueue &Q, QElemType &e)
{
    if(Q.rear == Q.rear)return 0;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1)%MAXQSIZE;
    return 1;
}




