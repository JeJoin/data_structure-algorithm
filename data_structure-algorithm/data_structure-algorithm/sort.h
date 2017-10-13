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

template <typename T>
void _QuickSort(T* arr, int l, int r)
{
    if (r <= l) {
        return;
    }

    T tmp = arr[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (arr[i] < tmp) {
            swap(arr[j + 1], arr[i]);
            j++;
        }
    }
    swap(arr[j], arr[l]);
    _QuickSort(arr, l, j-1);
    _QuickSort(arr, j+1, r);
}

template <typename T>
void QuickSort(T* arr, int n)
{
    _QuickSort(arr, 0, n - 1);
}

}
#endif // SORT_H
