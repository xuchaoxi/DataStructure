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


/*
 * function : quick_sort
 */
template <typename T>
void quick_sort(T data[], int first, int last)
{
    int lower = first+1;
    int upper = last;
    int t = rand() % (last-first) + first;  // !
    std::swap(data[first], data[t]);
    T& bound = data[first];
    while(lower <= upper)
    {
        while(data[lower] < bound)
        {
            ++lower;
        }
        while(bound < data[upper])
        {
            --upper;
        }
        if(lower < upper)
        {
            std::swap(data[lower], data[upper]);
            ++lower;
            --upper;
        }
        else      // ? 
            ++lower;
    }
    std::swap(data[upper], data[first]); 
    if(first < upper-1)
    {
        quick_sort(data, first, upper-1);
    }
    if(upper+1 < last)
    {
        quick_sort(data, upper, last);
    }
}
/*
 * function : QuickSort
 * time & mem : O(nlogn)[worst:O(n^2)], O(logn)
 * param : data[], size
 * con : data != NULL size > 0
 * con2 data (<=)
 * usage:
 * #include<algorithm>
 * #include<cstdlib>
 * #include<ctime>
 * int arr[] = {10,9,8,4,5,7,6,3,1,4};
 * QuickSort(arr, 10);
 */
template <typename T>
void QuickSort(T data[], int size)
{
    int i, max;
    if(size < 2)
        return;
    for(i = 1, max = 0;i < size;++i)
    {
        if(data[max] < data[i])
            max = i;
    }
    std:swap(data[size-1], data[max]);
    srand(time(0));
    quick_sort(data, 0, size-2);
}


/*
 * function : quick_sort
 */
template <typename T, typename Func>
void quick_sort(T data[], int first, int last, Func& f)
{
    int lower = first+1;
    int upper = last;
    int t = rand() % (last-first) + first;  // !
    std::swap(data[first], data[t]);
    T& bound = data[first];
    while(lower <= upper)
    {
        while(f(data[lower], bound))
        {
            ++lower;
        }
        while(f(bound, data[upper]))
        {
            --upper;
        }
        if(lower < upper)
        {
            std::swap(data[lower], data[upper]);
            ++lower;
            --upper;
        }
        else      // ? 
            ++lower;
    }
    std::swap(data[upper], data[first]); 
    if(first < upper-1)
    {
        quick_sort(data, first, upper-1);
    }
    if(upper+1 < last)
    {
        quick_sort(data, upper, last);
    }
}
/*
 * function : QuickSort
 * time & mem : O(nlogn)[worst:O(n^2)], O(logn)
 * param : data[], size,cmp
 * con : data != NULL size > 0
 * con2 data (f)
 * usage:
 * #include<algorithm>
 * #include<cstdlib>
 * #include<ctime>
 * bool cmp(int a, int b) { return a < b; }
 * int arr[] = {10,9,8,4,5,7,6,3,1,4};
 * QuickSort(arr, 10, cmp);
 */
template <typename T, typename Func>
void QuickSort(T data[], int size, Func f)
{
    int i, max;
    if(size < 2)
        return;
    for(i = 1, max = 0;i < size;++i)
    {
        if(data[max] < data[i])
            max = i;
    }
    std:swap(data[size-1], data[max]);
    srand(time(0));
    quick_sort(data, 0, size-2, f);
}


/*
 * function : partition
 */
template <typename T>
int Partition(T data[], int low, int high)
{
    T pivot = data[low];
    while(low < high)
    {
        while(low < high && data[high] > pivot)
        {
            --high;
        }
        data[low] = data[high];
        while(low < high && data[low] < pivot)
        {
            ++low;
        }
        data[high] = data[low];
    }
    data[low] = pivot;
    return low;
}
/*
 * function : QSort
 * time & mem : O(nlogn)[worst O(n^2)] O(logn)
 * param : data size
 * con : data != NULL,size > 0
 * con2 : data (<=)
 * usage:
 * QSort(data, 0, size-1);
 */
template <typename T>
void QSort(T data[], int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = Partition(data, low, high);
        QSort(data, 0, mid-1);
        QSort(data, mid+1, high);
    }
}


/*
 * function : MergeSort
 * time & mem : O(nlogn) O(n)
 * usage :
 * #include<algorithm>
 * int arr[] = {10,9,8,4,5,7,6,3,1,4};
 * MergeSort(arr, 10);
 */
template <typename T>
void MergeSort(T data[], int size)
{
    if(size > 1)
    {
        int mid = size/2;
        int numOfleft = mid;
        int numOfright = size - mid;
        T* left = new T[numOfleft];
        T* right = new T[numOfright];
        //divide 
        std::copy(data, data+numOfleft, left);
        std::copy(data+numOfleft, data+size, right);
        MergeSort(left, numOfleft);
        MergeSort(right, numOfright);
        // merge
        std::merge(left, left+numOfleft, right, right+numOfright, data);
        delete[] left;
        delete[] right;
    }
}


/*
 * function : MergeSort
 * time & mem : O(nlogn) O(n)
 * usage :
 * #include<algorithm>
 * bool cmp(int a, int b) { return a < b; }
 * int arr[] = {10,9,8,4,5,7,6,3,1,4};
 * MergeSort(arr, 10);
 */
template <typename T, typename Func>
void MergeSort(T data[], int size, Func f)
{
    if(size > 1)
    {
        int mid = size/2;
        int numOfleft = mid;
        int numOfright = size - mid;
        T* left = new T[numOfleft];
        T* right = new T[numOfright];
        MergeSort(left, numOfleft, f);
        MergeSort(right, numOfright, f);
        // divide
        std::copy(data, data+numOfleft, left);
        std::copy(data+numOfleft, data+size, right);
        //merge
        std::merge(left, numOfleft, right, numOfright, data, f);
        delete[] left;
        delete[] right;
    }
}


/*
 * function : head_down
 */
template <typename T>
void head_down(T data[], int i, const int &size)
{
    int p = i*2+1;
    while(p < size)
    {
        if(p+1 < size)
        {
            if(data[p] < data[p+1])
            {
                ++p;
            }
        }
        if(data[i] < data[p])
        {
            std::swap(data[p], data[i]);
            i = p;
            p = i*2+1;
        }
        else
            break;
    }
}
/*
 * function : HeapSort
 * param : data size
 * con : data <=
 * usage :
 * #include<algorithm>
 * int arr[] = {10,9,8,4,5,7,6,3,1,4};
 * HeapSort(arr, 10);
 */
template <typename T>
void HeapSort(T data[], int size)
{
    int i;
    for(i = (size-1)/2;i >= 0;--i)
    {
        head_down(data, i, size);
    }
    for(i = size-1;i > 0;--i)
    {
        std:swap(data[0], data[i]);
        head_down(data, 0, i);
    }
}

/*
 * function : head_down
 */
template <typename T, typename Func>
void head_down(T data[], int i, const int &size, Func& f)
{
    int p = i*2+1;
    while(p < size)
    {
        if(p+1 < size)
        {
            if(f(data[p], data[p+1]))
            {
                ++p;
            }
        }
        if(f(data[i], data[p]))
        {
            std::swap(data[p], data[i]);
            i = p;
            p = i*2+1;
        }
        else
            break;
    }
}
/*
 * function : HeapSort
 * param : data size
 * con : data <=
 * usage :
 * #include<algorithm>
 * bool cmp(int a, int b) { return a < b; }
 * int arr[] = {10,9,8,4,5,7,6,3,1,4};
 * HeapSort(arr, 10);
 */
template <typename T, typename Func>
void HeapSort(T data[], int size, Func& f)
{
    int i;
    for(i = (size-1)/2;i >= 0;--i)
    {
        head_down(data, i, size, f);
    }
    for(i = size-1;i > 0;--i)
    {
        std:swap(data[0], data[i]);
        head_down(data, 0, i, f);
    }
}
