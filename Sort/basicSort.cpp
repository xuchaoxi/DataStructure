/*************************************************************************
	> File Name: insertSort.cpp
	> Author: Chaoxi Xu
	> Mail: xuchaoxikb@gmail.com 
	> Created Time: Sun 26 Mar 2017 10:53:58 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

/*
 * param data[], size
 * data!=NULL size > 0
 * data (<=)
 * int arr[] = {10,9,8,4,5,7,6,3,1,4};
 * InsertSort(arr, 10);
 */
template <typename T>
void InsertSort(T data[], int size)
{
    int i, j;
    T tmp;
    for(i = 1;i < size;i++)
    {
        if(data[i] < data[i-1])  // not necessary
        {
            tmp = data[i];
            for(j = i;j > 0 && tmp < data[j-1];--j)
            {
                data[j] = data[j-1];
            }
            data[j] = tmp;
        }
    }
}

/*
 * param data size cmp
 * data!=NULL size > 0
 * bool cmp(int a, int b) { return a < b; }
 * int arr[] = {10,9,8,4,5,7,6,3,1,4};
 * InsertSort(arr, 10, cmp);
 */
template <typename T, typename Func>
void InsertSort(T data[], int size, Func f)
{
    int i, j;
    T tmp;
    for(i = 1;i < size;i++)
    {
        if(f(data[i], data[i-1]))  // not necessary
        {
            tmp = data[i];
            for(j = i;j > 0 && f(tmp, data[j-1]);--j)
            {
                data[j] = data[j-1];
            }
            data[j] = tmp;
        }
    }
}

