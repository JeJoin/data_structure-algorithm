#ifndef __SORT_H__
#define __SORT_H__

#include <algorithm>
#include <MaxHeap.hpp>
template <typename T>
class MaxHeap;
using namespace std;
namespace sort {

    template <typename T>
    void SelectSort(T* arr, int n) {
        for (int i = 0; i < n; i++) {

            int idx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[idx]) {
                    idx = j;
                }
            }
            swap(arr[i], arr[idx]);
        }
    }

    template <typename T>
    void BubbleSort(T* arr, int n) {
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    template <typename T>
    void InsertSort(T* arr, int n) {
        for (int i = 1; i < n; i++) {

            int j;
            T tmp = arr[i];
            for (j = i; j > 0 && arr[j - 1] > tmp; j--) {
                arr[j] = arr[j - 1];
            }
            arr[j] = tmp;
        }
    }

    template <typename T>
    void ShellSort(T* arr, int n) {
        for (int gap = n / 2; gap > 0; gap /= 2) {

            for (int i = gap; i < n; i++) {
                int j;
                T tmp = arr[i];
                for (j = i; j >= gap && arr[j - gap] > tmp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = tmp;
            }
        }
    }

    template<typename T>
    void ShellSort1(T arr[], int n) {

        int h = 1;
        while (h < n / 3)
            h = 3 * h + 1;
        // ���� increment sequence: 1, 4, 13, 40, 121, 364, 1093...

        while (h >= 1) {

            // h-sort the array
            for (int i = h; i < n; i++) {

                // �� arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]... ʹ�ò�������
                T e = arr[i];
                int j;
                for (j = i; j >= h && e < arr[j - h]; j -= h)
                    arr[j] = arr[j - h];
                arr[j] = e;
            }

            h /= 3;
        }
    }

    // ��arr[l, mid]��arr[mid+1, r]���кϲ�
    template <typename T>
    void _Merge(T* arr, int l, int mid, int r) {

        T* aux = new T[r - l + 1];
        for (int i = l; i <= r; i++) {
            aux[i - l] = arr[i];
        }
        int i = l;
        int j = mid + 1;
        for (int k = l; k <= r; k++) {
            if (i > mid) {
                arr[k] = aux[j - l];
                j++;
            } else if (j > r) {
                arr[k] = aux[i - l];
                i++;
            } else if (aux[i - l] < aux[j - l]) {
                arr[k] = aux[i - l];
                i++;
            } else {
                arr[k] = aux[j - l];
                j++;
            }
        }
        delete[] aux;
    }

    template <typename T>
    void _Merge1(T* arr, int l, int mid, int r) {
        int auxsize = r - l + 1;
        int * aux = new T[auxsize];
        for (int i = 0; i < auxsize; i++) {
            aux[i] = arr[l + i];
        }

        int i = l;
        int j = mid + 1;

        for (int k = l; k <= r; k++) {
            if (i > mid ) {
                arr[k] = aux[j - l];
                j++;
            } else if (j > r) {
                arr[k] = aux[i - l];
                i++;
            } else if (aux[i - l] > aux[j - l]) {
                arr[k] = aux[j - l];
                j++;
            } else if (aux[i - l] < aux[j - l]) {
                arr[k] = aux[i - l];
                i++;
            } else {
                arr[k++] = aux[i - l];
                arr[k] = aux[j - l];
                i++;
                j++;
            }

        }
    }
    // ����arr[l, r]���й鲢����;l,r�Ǳ�����
    template <typename T>
    void _MergeSort(T* arr, int l, int r) {
        // arr���Ȳ�����15��ʱ��ʹ�ò�������
        // �������㷨Ч��
        if (r - l <= 15) {
            InsertSort(arr + l, r - l + 1);
            return;
        }
        if (l >= r) {
            return;
        }
        int mid = (r + l) / 2;
        _MergeSort(arr, l, mid);
        _MergeSort(arr, mid + 1, r);
        _Merge1(arr, l, mid, r);
    }

    template <typename T>
    void MergeSort(T* arr, int n) {
        _MergeSort(arr, 0, n - 1);
    }

    template <typename T>
    void MergeSortBU(T* arr, int n) {
        // ��Ԫ������16��ʱʹ�ò�������
        for (int i = 0; i < n; i += 16) {
            InsertSort(arr + i, 16);
        }

        // ÿ�ι鲢Ԫ�صĸ���16��32��64...
        for (int count = 16; count <= n; count += count) {
            // ÿһ���ڹ鲢�Ĺ�����Ԫ����ʼ��λ��
            for (int i = 0; i + count < n; i += count * 2) {
                if (arr[i + count - 1] > arr[i + count]) {
                    _Merge(arr, i, i + count - 1, min(i + 2 * count - 1, n - 1));
                }
            }
        }
    }

    template <typename T>
    int _Partition(T* arr, int l, int r) {
        // �Ż�1: ��������������ʱ��,�㷨���˻���O(n^2)������㷨
        // �������ѡ��һ���궨Ԫ�أ�������������ֵΪO(nlogn)
        // ������ϱ����˻���O(n^2)
        swap(arr[l], arr[(rand() % (r - l + 1)) + l]);

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
    void _QuickSort(T* arr, int l, int r) {
        if (r <= l) {
            return;
        }
        int p = _Partition(arr, l, r);
        _QuickSort(arr, l, p - 1);
        _QuickSort(arr, p + 1, r);
    }

    // ����Ŀ��������Ե�һ��Ԫ����Ϊ��׼
    template <typename T>
    void QuickSort(T* arr, int n) {
        srand(time(NULL));
        _QuickSort(arr, 0, n - 1);
    }

    // 2·��������
    // �Ż�2: ���ڴ��ڴ����ظ�Ԫ�ص���������Ż�
    // �����ڴ����ظ�Ԫ�ص�ʱ��,�㷨Ҳ���˻���O(n^2)������㷨
    // ȱ�㣺
    template <typename T>
    int _Partition2(T* arr, int l, int r) {
        swap(arr[l], arr[(rand() % (r - l + 1)) + l]);

        T tmp = arr[l];
        // arr[l] >= arr[l, i); arr[l] <= arr(j, r]
        int i = l + 1, j = r;


        while (true) {
            while (i <= r && arr[i] < tmp) {
                i++;
            }
            while (j >= l + 1 && arr[j] > tmp) {
                j--;
            }

            if (j < i) {
                break;
            }

            swap(arr[i++], arr[j--]);
        }

        swap(arr[l], arr[j]);
        return j;
    }

    template <typename T>
    void _QuickSort2(T* arr, int l, int r) {
        if (r <= l) {
            return;
        }
        int p = _Partition2(arr, l, r);
        _QuickSort2(arr, l, p - 1);
        _QuickSort2(arr, p + 1, r);
    }

    template <typename T>
    void QuickSort2(T* arr, int n) {
        srand(time(NULL));
        _QuickSort2(arr, 0, n - 1);
    }

    // 3·��������
    // ����������ͨ���궨Ԫ�رȽϷֳ���������
    // С�ڱ궨�����ڱ궨�����ڱ궨
    // ���������ڴ����ظ�Ԫ��Ҳ�ܸ�Чִ���㷨
    template <typename T>
    void _QuickSort3(T* arr, int l, int r) {
        if (r - l <= 16) {
            InsertSort(arr + l, r - l + 1);
            return;
        }

        swap(arr[l], arr[(rand() % (r - l + 1)) + l]);

        int tmp = arr[l];

        int lt = l;     // arr[l...lt] < tmp
        int gt = r + 1; // arr[gt...r] > tmp
        int i = l + 1;  // arr[lt+1...i-1] == tmp

        while (gt > i) {
            if (arr[i] < tmp) {
                swap(arr[++lt], arr[i++]);
            } else if (arr[i] > tmp) {
                swap(arr[--gt], arr[i]);
            } else { // tmp == arr[i]
                i++;
            }
        }

        swap(arr[lt], arr[l]);

        _QuickSort3(arr, l, lt - 1);
        _QuickSort3(arr, gt, r);
    }

    template <typename T>
    void QuickSort3(T* arr, int n) {
        srand(time(NULL));
        _QuickSort3(arr, 0, n - 1);
    }

    template <typename T>
    void HeapSort(T* arr, int n) {
        MaxHeap<T> heap(n);
        for (int i = 0; i < n; i++) {
            heap.insert(arr[i]);
        }

        for (int i = n - 1; i >= 0; i--) {
            arr[i] = heap.extractMax();
        }
    }

    template <typename T>
    void HeapSort1(T* arr, int n) {
        MaxHeap<T> heap(arr, n);
        for (int i = n - 1; i >= 0; i--) {
            arr[i] = heap.extractMax();
        }
    }

    template <typename T>
    void _ShifyDown(T* arr, int n, int position) {
        while (2 * position + 1 < n) {
            int p = position * 2 + 1;
            if (p + 1 < n && arr[p] < arr[p + 1]) {
                p++;
            }

            if (arr[position] >= arr[p]) {
                break;
            }

            std::swap(arr[position], arr[p]);
            position = p;
        }
    }

    template <typename T>
    void HeapSort2(T* arr, int n) {
        // heapify
        for (int i = (n - 1) / 2; i >= 0; i--) {
            _ShifyDown(arr, n, i);
        }

        // ��ֻʣ1��ʱ���轻��
        for (int i = n - 1; i > 0; i--) {
            std::swap(arr[0], arr[i]);
            _ShifyDown(arr, i, 0);
        }
    }
}
#endif // __SORT_H__
