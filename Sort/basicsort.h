/*************************************************************************
	> File Name: basicsort.h
	> Author: Chaoxi Xu
	> Mail: xuchaoxikb@gmail.com 
	> Created Time: Sun 26 Mar 2017 10:53:58 AM CST
 ************************************************************************/

#ifndef _BASICSORT_H
#define _BASICSORT_H
#endif

/*
 * function : InsertSort
 * time & mem : O(n^2) O(1)
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
 * time & mem : O(n^2) O(1)
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
 * time & mem : O(n^2) O(1)
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
 * time & mem : O(n^2) O(1)
 * param : data size cmp
 * con : data!=NULL size>0
 * con2 : data (f)
 * usage:
 * #include<algorithm>
 * int arr[] = {10,9,8,4,5,7,6,3,1,4};
 * bool cmp(int a, int b) { return a < b; }
 * SelectSort(arr, 10);
 */
template <typename T, typename Func>
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
 * time & mem : O(n^2) O(1)
 * param : data[], size
 * con : data!=NULL size > 0
 * con2 : data (<=)
 * usage:
 * #include<algorithm>
 * int arr[] = {10,9,8,4,5,7,6,3,1,4};
 * BubbleSort(arr, 10);
 */
template <typename T>
void BubbleSort(T data[], int size)
{
    int i, j;
    for(i = 0;i < size-1;++i)
    {
        for(j = size-1;j > i;--j)
        {
            if(data[j] < data[j-1])
            {
                std::swap(data[j], data[j-1]);
            }
        }
    }
}


/*
 * function : BubbleSort
 * time & mem : O(n^2) O(1)
 * param : data[], size cmp
 * con : data!=NULL size > 0
 * con2 : data (cmp)
 * usage:
 * #include<algorithm>
 * bool cmp(int a, int b) { return a < b; }
 * int arr[] = {10,9,8,4,5,7,6,3,1,4};
 * BubbleSort(arr, 10);
 */
template <typename T, typename Func>
void BubbleSort(T data[], int size, Func f)
{
    int i, j;
    for(i = 0;i < size-1;++i)
    {
        for(j = size-1;j > i;--j)
        {
            if(f(data[j], data[j-1]))
            {
                std::swap(data[j], data[j-1]);
            }
        }
    }
}


/*
 * function : ShellSort
 * Time & mem : 
 * param : data[], size
 * con : data!=NULL size > 0
 * con2 : data (<=)
 * usage:
 * int arr[] = {10,9,8,4,5,7,6,3,1,4};
 * ShellSort(arr, 10);
 */
template <typename T>
void ShellSort(T data[], int size)
{
    int i, j, hCnt, h;
    int arr[20], k;
    T tmp;
    for(h = 1, i = 0;h < size;++i)
    {
        arr[i] = h;
        h = 3*h+1;   // 3^20 > 2^32 
    }
    for(i--;i >= 0;--i)  // i is the index of arr 
    {
        h = arr[i];    // h is the increment 
        for(hCnt = h;hCnt < 2*h;++hCnt)
        {
            for(j = hCnt;j < size;j += h)
            {
                
                tmp = data[j];
                k = j;
                while(k-h >= 0 && tmp < data[k-h])
                {
                    data[k] = data[k-h];
                    k -= h;
                }
                data[k] = tmp;
            }
        }
    }
}


/*
 * function : ShellSort
 * Time & mem : 
 * param : data[], size, cmp
 * con : data!=NULL size > 0
 * con2 : data (f)
 * usage:
 * int cmp(int a, int b) { return a < b; }
 * int arr[] = {10,9,8,4,5,7,6,3,1,4};
 * ShellSort(arr, 10, cmp);
 */
template <typename T, typename Func>
void ShellSort(T data[], int size, Func f)
{
    int i, j, hCnt, h;
    int arr[20], k;
    T tmp;
    for(h = 1, i = 0;h < size;++i)
    {
        arr[i] = h;
        h = 3*h+1;   // 3^20 > 2^32 
    }
    for(i--;i >= 0;--i)  // i is the index of arr 
    {
        h = arr[i];    // h is the increment 
        for(hCnt = h;hCnt < 2*h;++hCnt)
        {
            for(j = hCnt;j < size;j += h)
            {
                
                tmp = data[j];
                k = j;
                while(k-h >= 0 && f(tmp, data[k-h]))
                {
                    data[k] = data[k-h];
                    k -= h;
                }
                data[k] = tmp;
            }
        }
    }
}
