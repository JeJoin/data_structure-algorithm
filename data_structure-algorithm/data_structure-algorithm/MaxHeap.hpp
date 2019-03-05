#include <common.h>

template <typename T>
class MaxHeap {
public:
    MaxHeap(int capacity) {
        m_elements = new T[capacity + 1];
        m_capacity = capacity;
        m_size = 0;
    }

    MaxHeap(T* arr, int n) {
        m_elements = new T[n + 1];
        m_capacity = n;

        for (int i = 0; i < n; i++) {
            m_elements[i + 1] = arr[i];
        }
        m_size = n;

        for (int i = m_size / 2; i >= 1; i--) {
            shiftDown(i);
        }
    }

    ~MaxHeap() {
        delete[] m_elements;
        m_capacity = 0;
        m_size = 0;
    }

    bool isEmpty() {
        return m_size <= 0;
    }

    bool isFull() {
        return m_capacity == m_size - 1;
    }

    int size() {
        return m_size;
    }

    void insert(T item) {
        assert(!isFull());

        m_elements[m_size + 1] = item;
        m_size++;
        shiftUp(m_size);
    }

    T extractMax() {
        assert(!isEmpty());
        T ret = m_elements[1];
        std::swap(m_elements[m_size], m_elements[1]);
        m_size--;
        shiftDown(1);
        return ret;
    }

private:
    void shiftUp(int position) {
#if 0
        int p = position / 2;
        if (position > 1 && m_elements[p] < m_elements[position]) {
            std::swap(m_elements[p], m_elements[position]);
            shiftUp(p);
        }
#else
        int p = position;
        while (p > 1 && m_elements[p/2] < m_elements[p]) {
            std::swap(m_elements[p / 2], m_elements[p]);
            p /= 2;
        }
#endif
    }

    void shiftDown(int parentIdx) {
        // parentIdx 是一个待交换的位置
        while (parentIdx * 2 <= m_size) {
            int swapIdx = parentIdx * 2; // parentIdx的左结点
            if (swapIdx + 1 <= m_size && m_elements[swapIdx] < m_elements[swapIdx + 1]) {
                swapIdx += 1;
            }
            if (m_elements[swapIdx] <= m_elements[parentIdx]) {
                break;
            }

            std::swap(m_elements[swapIdx], m_elements[parentIdx]);
            parentIdx = swapIdx;
        }
    }

public:
    void testPrint() {
        cout << "=============================================" << endl;
        if (size() >= 100) {
            cout << "Fancy print can only work for less than 100 int";
            return;
        }

        if (typeid(T) != typeid(int)) {
            cout << "Fancy print can only work for int item";
            return;
        }

        cout << "The Heap size is: " << size() << endl;
        cout << "data in heap: ";
        for (int i = 1; i <= size(); i++)
            cout << m_elements[i] << " ";
        cout << endl;
        cout << endl;

        int n = size();
        int max_level = 0;
        int number_per_level = 1;
        while (n > 0) {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }

        int max_level_number = int(pow(2, max_level - 1));
        int cur_tree_max_level_number = max_level_number;
        int index = 1;
        for (int level = 0; level < max_level; level++) {
            string line1 = string(max_level_number * 3 - 1, ' ');

            int cur_level_number = std::min(m_size - int(pow(2, level)) + 1, int(pow(2, level)));
            bool isLeft = true;
            for (int index_cur_level = 0; index_cur_level < cur_level_number; index++, index_cur_level++) {
                putNumberInLine(m_elements[index], line1, index_cur_level, cur_tree_max_level_number * 3 - 1, isLeft);
                isLeft = !isLeft;
            }
            cout << line1 << endl;

            if (level == max_level - 1)
                break;

            string line2 = string(max_level_number * 3 - 1, ' ');
            for (int index_cur_level = 0; index_cur_level < cur_level_number; index_cur_level++)
                putBranchInLine(line2, index_cur_level, cur_tree_max_level_number * 3 - 1);
            cout << line2 << endl;

            cur_tree_max_level_number /= 2;
        }
    }
private:
    void putNumberInLine(int num, std::string &line, int index_cur_level, int cur_tree_width, bool isLeft) {

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width + 1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if (num >= 10) {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        } else {
            if (isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }

    void putBranchInLine(std::string &line, int index_cur_level, int cur_tree_width) {

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left = index_cur_level * (cur_tree_width + 1) + sub_sub_tree_width;
        assert(offset_left + 1 < line.size());
        int offset_right = index_cur_level * (cur_tree_width + 1) + sub_tree_width + 1 + sub_sub_tree_width;
        assert(offset_right < line.size());

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }



private:
    T * m_elements;
    int m_size;
    int m_capacity;
};