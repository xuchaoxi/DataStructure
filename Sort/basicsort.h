/*************************************************************************
	> File Name: basicsort.h
	> Author: Chaoxi Xu
	> Mail: xuchaoxikb@gmail.com 
	> Created Time: Mon 03 Apr 2017 02:37:02 PM CST
 ************************************************************************/

#ifndef _BASICSORT_H
#define _BASICSORT_H
template <typename T>
void InsertSort(T data[], int size);
template <typename T, typename Func>
void  InsertSort(T data[], int size, Func f);

template <typename T>
void SelectSort(T data[], int size);
template <typename T, typename Func>
void SelectSort(T data[], int size, Func f);

template <typename T>
void BubbleSort(T data[], int size);
template <typename T, typename Func>
void BubbleSort(T data[], int size, Func f);

template <typename T>
void ShellSort(T data[], int size);
template <typename T, typename Func>
void ShellSort(T data[], int size, Func f);

template <typename T>
void quick_sort(T data[], int first, int last);
template <typename T>
void QuickSort(T data[], int size);
template <typename T, typename Func>
void quick_sort(T data[], int first, int last, Func f);
template <typename T, typename Func>
void QuickSort(T data[], int size, Func f);

template <typename T>
int Partition(T data[], int low, int high);
template <typename T>
void QSort(T data[], int low, int high);

template <typename T>
void MergeSort(T data[], int size);
template <typename T, typename Func>
void MergeSort(T data[], int size, Func f);

template <typename T>
void head_down(T data[], int i, const int &size);
template <typename T>
void HeapSort(T data[], int size);
template <typename T, typename Func>
void head_down(T data[], int i, const int &size, Func &f);
template <typename T, typename Func>
void HeapSort(T data[], int size, Func &f);
#endif
