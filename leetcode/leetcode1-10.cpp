#include <common.h>

// leetcode - 1
vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> ret;
    map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {

        int tmp = nums[i];

        if (m.find(tmp) != m.end()) {
            ret.push_back(m[tmp]);
            ret.push_back(i);
            break;
        } else {
            m[target - tmp] = i;
        }
    }
    return ret;
}

void testTwoSum()
{
    vector<int> v = { 2, 7, 11, 15 };
    vector<int> ret = twoSum(v, 9);

    for(auto i : ret)
    {
        cout << i << " ";
    }
    cout << endl;
}


// leetcode - 2
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    int notation = 0;
    ListNode * head = NULL, * tail = NULL;
    list<int> list1, list2;

    while (l1 != NULL) {
        list1.push_back(l1->val);
        l1 = l1->next;
    }

    while (l2 != NULL) {
        list2.push_back(l2->val);
        l2 = l2->next;
    }

    while (!list1.empty() || !list2.empty()) {

        int val = 0;
        ListNode * node = new ListNode(0);

        if (!list1.empty() && !list2.empty()) {
            val = list1.front() + list2.front() + notation;
            list1.pop_front();
            list2.pop_front();
            
        } else if (!list1.empty() && list2.empty()) {
            val = list1.front() + notation;
            list1.pop_front();
            
        } else {
            val = list2.front() + notation;
            list2.pop_front();

        }
        if (val > 9) {
            notation = 1;
            val %= 10;
        } else {
            notation = 0;
        }
        node->val = val;

        if (head == NULL) {
            head = node;
        }
        if (tail != NULL) {
            tail->next = node;
        }
        tail = node;
    }

    if (notation == 1) {
        ListNode * node = new ListNode(1);
        if (tail != NULL) {
            tail->next = node;
        }
        tail = node;
    }

    return head;
}

void testAddTwoNumbers()
{
    ListNode head1(9), node1(3), node2(8);
    head1.next = &node2;
    //node2.next = &node1;

    ListNode head2(1), node3(6), node4(4);
    //head2.next = &node3;
    //node3.next = &node4;

    ListNode * ret = addTwoNumbers(&head1, &head2);

    while (ret != NULL) {
        cout << ret->val << " ";
        ret = ret->next;
    }

    cout << endl;
}

// leetcode - 3
int lengthOfLongestSubstring(string s)
{
    if (s.empty()) {
        return 0;
    }
    std::map<char, int> m;
    std::map<int, int> m1;
    int count = 0;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (m.find(c) == m.end()) {
            m[c] = 0;
            count++;
        } else {
            m1[count] = 0;
            m.clear();
            m[c] = 0;
            count = 1;
        }
    }

    return m1.crbegin()->first;
}

int lengthOfLongestSubstring1(string s)
{
    int  size, i = 0, j, k, max = 0;
    size = s.size();
    for (j = 0; j < size; j++) {
        for (k = i; k < j; k++)
            if (s[k] == s[j]) {
                i = k + 1;
                break;
            }
        if (j - i + 1 > max)
            max = j - i + 1;
    }
    return max;
}

void testLengthOfLongestSubstring()
{
    string str = "asdflhkjlklkjffasdf";
    std::cout << "sub length: " << lengthOfLongestSubstring1(str) << std::endl;
}