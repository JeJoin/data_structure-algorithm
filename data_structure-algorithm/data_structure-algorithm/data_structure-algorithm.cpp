// data_structure-algorithm.cpp : 定义控制台应用程序的入口点。
//

#include "sort.h"
#include "common.h"
#include "MaxHeap.hpp"

void testSort() {
    int n = 200000;
    int *arr = common::GetRandomArr(n, 0, 100);
    int *arr1 = common::CopyArr(arr, n);
    int *arr2 = common::CopyArr(arr, n);
    int *arr3 = common::CopyArr(arr, n);
    int *arr4 = common::CopyArr(arr, n);

    cout << "================= Sort Random Array =====================" << endl;
    //common::TestSort("BubbleSot", sort::BubbleSot, arr, n);
    //common::TestSort("SeletctionSort", sort::SelectSort, arr1, n);
    //common::TestSort("InsertSort", sort::InsertSort, arr2, n);

    //common::TestSort("ShellSort", sort::ShellSort, arr, n);
    //common::TestSort("ShellSort1", sort::ShellSort1, arr1, n);

    common::TestSort("MergeSort", sort::MergeSort, arr, n);
    //common::TestSort("QuickSort", sort::QuickSort, arr1, n);
    //common::TestSort("QuickSort2", sort::QuickSort2, arr2, n);
    common::TestSort("QuickSort3", sort::QuickSort3, arr3, n);
    common::TestSort("HeapSort", sort::HeapSort, arr4, n);
    common::TestSort("HeapSort1", sort::HeapSort1, arr2, n);
    common::TestSort("HeapSort2", sort::HeapSort2, arr1, n);

    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    cout << "================= Sort Near Order Array =====================" << endl;

    arr = common::CreateNearOrderArr(n, 10);
    arr1 = common::CopyArr(arr, n);
    arr2 = common::CopyArr(arr, n);
    arr3 = common::CopyArr(arr, n);
    arr4 = common::CopyArr(arr, n);

    common::TestSort("MergeSort", sort::MergeSort, arr, n);
    //common::TestSort("QuickSort", sort::QuickSort, arr1, n);
    //common::TestSort("QuickSort2", sort::QuickSort2, arr2, n);
    common::TestSort("QuickSort3", sort::QuickSort3, arr3, n);
    common::TestSort("HeapSort", sort::HeapSort, arr4, n);
    common::TestSort("HeapSort1", sort::HeapSort1, arr2, n);
    common::TestSort("HeapSort2", sort::HeapSort2, arr1, n);

    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
}

void testMaxHeap() {
    MaxHeap<int> heap(100);

    srand(time(NULL));
    for (int i = 0; i < 15; i++) {
        heap.insert(rand() % 100);
    }

    heap.testPrint();

    cout << "extract max: " ;
    while (!heap.isEmpty()) {
        cout << heap.extractMax() << " ";
    }

}

int main()
{
    testSort();
    //testMaxHeap();
    system("pause");
    return 0;
}

