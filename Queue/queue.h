/*************************************************************************
	> File Name: queue.h
	> Author: xu chaoxi
	> Mail: xuchaoxikb@gmail.com 
	> Created Time: Fri 13 Jan 2017 08:02:22 PM CST
 ************************************************************************/

#ifndef _QUEUE_H
#define _QUEUE_H
#endif

#include<iostream>

#define MAXQSIZE 100

typedef int QElemType;

typedef struct QNode {
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

typedef struct {
    QElemType *base;
    int front;
    int rear;
}SqQueue;

int InitQueue(LinkQueue &Q);

int DestroyQueue(LinkQueue &Q);

int ClearQueue(LinkQueue &Q);

int QueueEmpty(LinkQueue Q);

int QueueLength(LinkQueue Q);

int GetHead(LinkQueue Q, QElemType &e);

int EnQueue(LinkQueue &Q, QElemType e);

int DeQueue(LinkQueue &Q, QElemType &e);

void visit(QElemType e);

int QueueTraverse(LinkQueue Q, void (*visit)(QElemType e));

int InitQueue_Sq(SqQueue &Q);

int QueueLength_Sq(SqQueue Q);

int EnQueue_Sq(SqQueue &Q, QElemType e);

int DeQueue_Sq(SqQueue &Q, QElemType &e);

