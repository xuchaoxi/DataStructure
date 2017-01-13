/*************************************************************************
	> File Name: queue.cpp
	> Author: xu chaoxi
	> Mail: xuchaoxikb@gmail.com 
	> Created Time: Fri 13 Jan 2017 08:31:51 PM CST
 ************************************************************************/

#include<iostream>
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
