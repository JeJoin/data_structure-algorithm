// data_structure-algorithm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "sort.h"
#include "common.h"
using namespace std;
void sellsort(int *arr, int n)
{
    int gap, i, j;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {

            int tmp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > tmp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = tmp;
        }
    }
}

int main()
{
    int n = 1000000;
    int *arr = common::GetRandomArr(n, 0, n);
    int *arr1 = common::CopyArr(arr, n);
    int *arr2 = common::CopyArr(arr, n);
    int *arr3 = common::CopyArr(arr, n);

    //common::TestSort("SeletctionSort", sort::SelectSort, arr, n);
    //common::TestSort("InsertSort", sort::InsertSort, arr1, n);
    //common::TestSort("ShellSort", sort::ShellSort, arr2, n);
    //common::TestSort("ShellSort", sellsort, arr2, n);
    common::TestSort("MergeSort", sort::MergeSort, arr3, n);
    common::TestSort("QuickSort", sort::QuickSort, arr2, n);

    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    system("pause");
    return 0;
}

