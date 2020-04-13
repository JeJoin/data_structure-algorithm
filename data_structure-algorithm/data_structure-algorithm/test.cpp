#include <map>
#include "sort.h"
#include "common.h"
#include "search.h"
#include "MaxHeap.hpp"
#include "MaxIndexHeap.hpp"
#include "BST.hpp"
#include "3rd/FileOps.h"
#include "3rd/SequenceST.h"

void testSort() {
    int n = 20000;
    int *arr = common::GetRandomArr(n, 0, 20000);
    std::map<int, int *> m;
    for (int i = 0; i < 12; ++i) {
        m[i] = common::CopyArr(arr, n);
    }

    cout << "================= Sort Random Array =====================" << endl;
    //common::TestSort("BubbleSot", sort::BubbleSort, arr, n);
    common::TestSort("SeletctionSort", sort::SelectSort, m[1], n);
    common::TestSort("InsertSort", sort::InsertSort, m[2], n);
    common::TestSort("ShellSort", sort::ShellSort, m[3], n);
    common::TestSort("ShellSort1", sort::ShellSort1, m[4], n);
    common::TestSort("MergeSort", sort::MergeSort, m[5], n);
    common::TestSort("QuickSort", sort::QuickSort, m[6], n);
    common::TestSort("QuickSort2", sort::QuickSort2, m[7], n);
    common::TestSort("QuickSort3", sort::QuickSort3, m[8], n);
    common::TestSort("HeapSort", sort::HeapSort, m[9], n);
    common::TestSort("HeapSort1", sort::HeapSort1, m[10], n);
    common::TestSort("HeapSort2", sort::HeapSort2, m[11], n);

    delete[] arr;
    for (auto & itr = m.begin(); itr != m.end(); ++itr) {
        delete[] (itr->second);
    }
    m.clear();

    cout << "================= Sort Near Order Array =====================" << endl;
    arr = common::CreateNearOrderArr(n, 10);
    for (int i = 0; i < 10; ++i) {
        m[i] = common::CopyArr(arr, n);
    }

    common::TestSort("MergeSort", sort::MergeSort, arr, n);
    common::TestSort("QuickSort", sort::QuickSort, m[1], n);
    common::TestSort("QuickSort2", sort::QuickSort2, m[2], n);
    common::TestSort("QuickSort3", sort::QuickSort3, m[3], n);
    common::TestSort("HeapSort", sort::HeapSort, m[4], n);
    common::TestSort("HeapSort1", sort::HeapSort1, m[5], n);
    common::TestSort("HeapSort2", sort::HeapSort2, m[6], n);

    delete[] arr;
    for (auto & itr = m.begin(); itr != m.end(); ++itr) {
        delete[] (itr->second);
    }
    m.clear();
}

void testMaxHeap() {
    MaxHeap<int> heap(100);

    srand((unsigned int)time(NULL));
    for (int i = 0; i < 15; i++) {
        heap.insert(rand() % 100);
    }
    heap.testPrint();
    cout << "extract max: " ;
    while (!heap.isEmpty()) {
        cout << heap.extractMax() << " ";
    }
}

void testMaxIndexHeap() {
    MaxIndexHeap<int> heap(100);

    srand((unsigned int)time(NULL));
    cout << "============ before change =============" << endl;
    for (int i = 0; i < 15; i++) {
        heap.insert(i, rand() % 100);
    }
    heap.testPrint();
    heap.change(0, 99);

    cout << "============ after change =============" << endl;
    heap.testPrint();

    cout << "extract max: ";
    while (!heap.isEmpty()) {
        cout << heap.extractMax() << " ";
    }

    cout << endl;

    heap.testPrint();
}

void testBinarySearch() {
    int n = 10000000;
    int search = 5;
    int* arr = common::GetRandomArr(n, 0, n);
    sort::QuickSort3(arr, n);
    common::PrintArr(arr, n);

    cout << "search[ " << search << " ]: " << search::BinarySearch(arr, n, search) << endl;
    cout << "search[ " << search << " ]: " << search::BinarySearch(arr, 0, n-1, search) << endl;
}

void testBST() {
    string filename = "MoonAndSixpence.txt";
    vector<string> words;
    if (FileOps::readFile(filename, words)) {
        cout << "There are totally " << words.size() << " words in " << filename << endl;
        cout << endl;
        // test BST
        string target = "strickland";
        time_t startTime = clock();
        BST<string, int> bst = BST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); ++iter) {
            int *res = bst.search(*iter);
            if (res == NULL) {
                bst.insert(*iter, 1);
            } else {
                (*res)++;
            }
        }

        if (!bst.contain(target)) {
            cout << "BST doesn't have "<< target << endl;
            return;
        }

        cout << "[ " << target << " ]: " << *bst.search(target) << endl;
        time_t endTime = clock();
        cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;

        // test SST
        startTime = clock();
        SequenceST<string, int> sst = SequenceST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = sst.search(*iter);
            if (res == NULL) {
                sst.insert(*iter, 1);
            } else {
                (*res)++;
            }
        }
        cout << "[ " << target << " ]: " << *sst.search(target) << endl;
        endTime = clock();
        cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

        // sort
       // =============================== sort =================================
        bst.inOrder();
        cout << endl;
        cout << endl;

        // remove max
        // =========================== remove max ==============================
        string maxKey = bst.maximun();
        cout << "bst max key is " << maxKey << endl;
        bst.removeMax();
        if (bst.contain(target)) {
            cout << "bst has max key[ " << maxKey << " ]" << endl;
        } else {
            cout << "bst doesn't have max key[ " << maxKey << " ]" << endl;
        }
        cout << endl;

        // remove min
        // =========================== remove min ==============================
        string minKey = bst.minimun();
        cout << "bst min key is " << minKey << endl;
        bst.removeMin();
        if (bst.contain(minKey)) {
            cout << "bst has min key[ " << minKey << " ]" << endl;
        } else {
            cout << "bst doesn't have min key[ " << minKey << " ]" << endl;
        };
        cout << endl;

        // remove any key
        // ========================= remove any key ============================
        bst.remove(target);
        if (bst.contain(target)) {
            cout << "bst has key[ " << target << " ]" << endl;
        } else {
            cout << "bst doesn't have key[ " << target << " ]" << endl;
        }
    }
}

int main()
{
    testSort();
    //testMaxHeap();
    //testMaxIndexHeap();
    //testBinarySearch();
    //testBST();
    system("pause");
    return 0;
}

