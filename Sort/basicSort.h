/*************************************************************************
	> File Name: basicSort.h
	> Author: Chaoxi Xu
	> Mail: xuchaoxikb@gmail.com 
	> Created Time: Sun 26 Mar 2017 10:53:58 AM CST
 ************************************************************************/

#ifndef _BASICSORT_H
#define _BASICSORT_H
#endif

/*
 * function : InsertSort
 * param : data[], size
 * con : data!=NULL size > 0
 * con2 : data (<=)
 * usage:
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
 * function : InsertSort
 * param : data size cmp
 * con : data!=NULL size > 0
 * con: data (f)
 * usage:
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


/*
 * function : SelectSort
 * param : data size
 * con : data!=NULL size>0
 * con2 : data (<=)
 * usage:
 * #include<algorithm>
 * int arr[] = {10,9,8,4,5,7,6,3,1,4};
 * SelectSort(arr, 10);
 */
template <typename T>
void SelectSort(T data[], int size)
{
    int i, j, k;
    for(i = 0;i < size-1;++i)
    {
        k = i;
        for(j = i+1;j < size;++j)  // SelectMin key from i+1 to size
        {
            if(data[j] < data[k])
            {
                k = j;
            }
        }
        if(k != i)
        {
            std:swap(data[i], data[k]);
        }
    }
}

/*
 * function : SelectSort
 * param : data size cmp
 * con : data!=NULL size>0
 * con2 : data (f)
 * usage:
 * #include<algorithm>
 * int arr[] = {10,9,8,4,5,7,6,3,1,4};
 * bool cmp(int a, int b) { return a < b; }
 * SelectSort(arr, 10);
 */
template <template T, template Func>
void SelectSort(T data[], int size, Func f)
{
    int i, j, k;
    for(i = 0;i < size-1;++i)
    {
        k = i;
        for(j = i+1;j < size;++j)
        {
            if(f(data[j], data[k]))
            {
                k = j;
            }
        }
        if(k != i)
        {
            std::swap(data[i], data[k]);
        }
    }
}

/*
 * function : BubbleSort
 * param : data[], size
 * con : data!=NULL size > 0
 * con2 : data (<=)
 * usage:
 * #include<algorithm>
 * int arr[] = {10,9,8,4,5,7,6,3,1,4};
 * BubbleSort(arr, 10);
 */

