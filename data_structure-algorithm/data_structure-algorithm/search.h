#include <common.h>

using namespace common;
/* ��ʵ��
 * ==== ���ֲ��� ====
 * floor �� ceil���������������д����ظ���ʱ�����ҵ���һ���ظ���������һ���ظ���
 */

namespace search {

    template <typename T>
    int BinarySearch(T* arr, int n, T target) {

        // arr[l...r]
        int r = n - 1, l = 0;

        // ���
        //int mid = (r + l) / 2;
        int mid = l + (r - l) / 2;

        while (l <= r) {
            if (arr[mid] == target) {
                return mid;
            }
            if (arr[mid] < target) {
                l = mid + 1;
            } else if (arr[l + mid] > target) {
                r = mid - 1;
            }
            mid = l + (r - l) / 2;
        }
        return -1;
    }

    template <typename T>
    int BinarySearch(T* arr, int l, int r, T target) {
        if (l > r) {
            return -1;
        }

        // ���
        //int mid = (r + l) / 2;
        int mid = l + (r - l) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[l + mid] > target) {
            return BinarySearch(arr, l, mid - 1, target);
        } else if(arr[l + mid] <target) {
            return BinarySearch(arr, mid + 1, r, target);
        }
    }
} // namespace sort