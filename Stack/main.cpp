/*************************************************************************
	> File Name: main.cpp
	> Author: xu chaoxi
	> Mail: xuchaoxikb@gmail.com 
	> Created Time: Fri 13 Jan 2017 07:46:09 PM CST
 ************************************************************************/

#include<iostream>
#include "stack.cpp"
using namespace std;

int main()
{
    SqStack s;
    InitStack(s);
    for(int i = 1; i < 10;i++)
        Push(s, 2*i);
    StackTraverse(s, visit);
    return 0;

}

