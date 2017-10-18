#ifndef SORT_H
#define SORT_H

#include <algorithm>
namespace sort
{

template <typename T>
void SelectSort(T* arr, int n)
{
    for(int i = 0; i < n; i++) {

        int idx = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[idx]) {
                idx = j;
            }
        }
        std::swap(arr[i], arr[idx]);
    }
}

template <typename T>
void InsertSort(T* arr, int n)
{
    for(int i = 1; i < n; i++) {

        int j;
        T tmp = arr[i];
        for(j = i; j > 0 && arr[j-1] > tmp; j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = tmp;
    }
}

template <typename T>
void ShellSort(T* arr, int n)
{
    for(int gap = n/2; gap > 0; gap /= 2) {

        for(int i = gap; i < n;  i++) {
            int j;
            T tmp = arr[i];
            for(j = i; j >= gap && arr[j-gap] > tmp; j -= gap) {
                arr[j] = arr[j-gap];
            }
            arr[j] = tmp;
        }
    }
}

template <typename T>
void _Merge(T* arr, int l, int mid, int r)
{
    T* aux = new T[r-l+1];
    for(int i = l; i <= r; i++) {
       aux[i-l] = arr[i];
    }
    int i = l;
    int j = mid+1;
    for(int k = l; k <= r; k++) {
        if(i > mid) {
            arr[k] = aux[j-l];
            j++;
        } else if(j > r) {
            arr[k] = aux[i-l];
            i++;
        } else if(aux[i-l] < aux[j-l]) {
            arr[k] = aux[i-l];
            i++;
        } else {
            arr[k] = aux[j-l];
            j++;
        }
    }
    delete[] aux;
}

template <typename T>
void _MergeSort(T* arr, int l, int r)
{
    if(r-l <= 15) {
        InsertSort(arr+l, r-l+1);
        return;
    }
    if(l >= r) {
        return;
    }
    int mid = (r+l)/2;
    _MergeSort(arr, l, mid);
    _MergeSort(arr, mid+1, r);
    _Merge(arr, l, mid, r);
}

template <typename T>
void MergeSort(T* arr, int n)
{
    _MergeSort(arr, 0, n-1);
}

template <typename T>
void MergeSortBU(T* arr, int n)
{
    for (int i = 0; i < n; i += 16) {
        InsertSort(arr + i, 16);
    }

    for (int count = 16; count <= n; count += count) {
        for (int i = 0; i + count < n; i += count * 2) {
            if (arr[i+count-1] > arr[i + count]) {
                _Merge(arr, i, i+count-1, min(i+2*count-1, n-1));
            }
        }
    }
}

// 这种快速排序的方式当数组近乎有序是 排序情况最差
// 所以随机选择一个标定元素，该排序的期望值为nlogn
// 这个快速排序加上随机算法在近乎有序的数组也可以正常运行
// 但是如果该数组中有大量重复的元素也会退化成On^2
template <typename T>
int _Partition(T* arr, int l, int r)
{
    swap(arr[l], arr[rand() % (r - l + 1) + l]);

    int j = l;
    T tmp = arr[l];
    for (int i = l + 1; i <= r; i++) {
        if (arr[i] < tmp) {
            swap(arr[j + 1], arr[i]);
            j++;
        }
    }
    swap(arr[j], arr[l]);
    return j;
}

template <typename T>
void _QuickSort(T* arr, int l, int r)
{
    if (r <= l) {
        return;
    }
    int p = _Partition(arr, l, r);
    _QuickSort(arr, l, p-1);
    _QuickSort(arr, p+1, r);
}

// 常规的快速排序，以第一个元素作为标准
template <typename T>
void QuickSort(T* arr, int n)
{
    srand(time(NULL));
    _QuickSort(arr, 0, n - 1);
}

template <typename T>
int _Partition2(T* arr, int l, int r)
{
    swap(arr[l], arr[rand() % (r - l + 1) + l]);

    T tmp = arr[l];
    int j = l;
    return j;
}

template <typename T>
void _QuickSort2(T* arr, int l, int r)
{
    if (r <= l) {
        return;
    }
    int p = _Partition2(arr, l, r);
    _QuickSort2(arr, l, p-1);
    _QuickSort2(arr, p+1, r);
}

template <typename T>
void QuickSort2(T* arr, int n)
{
    srand(time(NULL));
    _QuickSort(arr, 0, n - 1);
}
}
#endif // SORT_H
