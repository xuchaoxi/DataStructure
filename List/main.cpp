/*************************************************************************
	> File Name: main.cpp
	> Author: xu chaoxi
	> Mail: xuchaoxikb@gmail.com 
	> Created Time: Tue 03 Jan 2017 03:14:16 PM CST
 ************************************************************************/

#include<stdio.h>
#include"sqlist.h"
int main()
{
    SqList L;
    InitList_Sq(L);
    printf("%d\n",L.listsize);
    return 0;
}
