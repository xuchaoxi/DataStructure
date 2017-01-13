/*************************************************************************
	> File Name: queue.cpp
	> Author: xu chaoxi
	> Mail: xuchaoxikb@gmail.com 
	> Created Time: Fri 13 Jan 2017 08:31:51 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include "queue.h"
using namespace std;

int InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear  = (QueuePtr)malloc(sizeof(QNode));
    if(!Q.front)exit(EXIT_FAILURE);
    Q.front->next = NULL;
    return 1;
}

int DestroyQueue(LinkQueue &Q)
{
    while(Q.front) {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
}

int ClearQueue(LinkQueue &Q)
{
    Q.rear = Q.front;
    QueuePtr p, q;
    p = Q.front->next;
    Q.front->next = NULL;
    while(p) {
        q = p->next;
        free(p);
        p = q;
    }
    return 1;
}

int QueueEmpty(LinkQueue Q)
{
    return (Q.front == Q.rear);
}

int QueueLength(LinkQueue Q)
{
    QueuePtr p;
    int cnt = 0;
    p = Q.front->next;
    while(p)
    {
        cnt++;
        p = p->next;
    }
    return cnt;
}

int GetHead(LinkQueue Q, QElemType &e)
{
    e = Q.front->next->data;
    return 1;
}

int EnQueue(LinkQueue &Q, QElemType e)
{
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode)); 
    if(p) {
        p->data = e;
        p->next = NULL;
        Q.rear->next = p;
        Q.rear = p;
        return 1;
    }
    return 0;
}

int DeQueue(LinkQueue &Q, QElemType &e)
{
    if(Q.front == Q.rear)
        return 0;
    QueuePtr p = Q.front->next;
    if(p) {
        e = p->data;
        Q.front->next = p->next;
        if(Q.rear==p)Q.rear = Q.front;
        free(p);
        return 1;
    }
    else return 0;
}

void print(QElemType e)
{
    cout<<e<<" ";
}

int QueueTraverse(LinkQueue Q, void (*visit)(QElemType e))
{
   QueuePtr p = Q.front->next;
    while(p) {
        visit(p->data);
        p = p->next;
    }
    cout<<endl;
    return 1;
}


