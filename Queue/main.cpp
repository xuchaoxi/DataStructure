/*************************************************************************
	> File Name: main.cpp
	> Author: xu chaoxi
	> Mail: xuchaoxikb@gmail.com 
	> Created Time: Fri 13 Jan 2017 09:55:34 PM CST
 ************************************************************************/

#include<iostream>
#include "queue.cpp"
using namespace std;

int main()
{
    LinkQueue Q;
    InitQueue(Q);
    QElemType e;
    for(int i = 1; i < 10;i++)
        EnQueue(Q, 2*i);
    QueueTraverse(Q, print);
    for(int i = 1;i < 10;i++)
    {
        DeQueue(Q, e);
        cout<<e<<" ";
    }
    cout<<endl;
    return 0;
}
