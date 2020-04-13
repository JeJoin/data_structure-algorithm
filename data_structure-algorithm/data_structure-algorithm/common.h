#ifndef COMMON_H
#define COMMON_H

#include <time.h>
#include <cassert>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

namespace common
{
// Create a range of [rangeL, rangeR] array
int* GetRandomArr(int n, int rangeL, int rangeR)
{
    assert(rangeL <= rangeR);
    int *arr = new int[n];
    srand((unsigned int)time(NULL));
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    }
    return arr;
}

template <typename T>
void PrintArr(T *arr, int n)
{
    for(int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
bool IsSorted(T *arr, int n)
{
    for(int i = 0; i < n-1; i++) {
        if(arr[i] > arr[i+1]) {
            return false;
        }
    }
    return true;
}

template <typename T>
void TestSort(const std::string &name, void(*sort)(T*arr, int n), T* arr, int n)
{
   clock_t start = clock();
   sort(arr, n);
   clock_t end = clock();

   std::cout << name << " Run Time:"
             << (double)(end-start)/CLOCKS_PER_SEC
             << " s" << std::endl;

   assert(IsSorted(arr, n));
   return;
}

template <typename T>
T* CopyArr(T* arr, int n)
{
    T* retArr = new T[n];
    for(int i = 0; i < n; i++) {
        retArr[i] = arr[i];
    }
    return retArr;
}

int* CreateNearOrderArr(int n, int revers)
{
    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        arr[i] = i;
    }
    srand((unsigned int)time(NULL));
    for(int j = 0; j < revers; j++) {
       int x = rand()%n;
       int y = rand()%n;
       std::swap(arr[x], arr[y]);
    }

    return arr;
}

} // namespace common
#endif // COMMON_H

