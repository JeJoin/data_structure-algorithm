#include <common.h>
#if PRIMARY_ALGORITHMS_TREE
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*����һ�����������ҳ��������ȡ�
�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣*/
int maxDepth(TreeNode* root)
{
    if (root == nullptr) {
        return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

void testMaxDepth()
{
    TreeNode root(0);
    TreeNode node1(1), node2(2), node3(3);
    root.left = &node1;
    root.left->left = &node2;
    root.left->left->left = &node3;

    cout << maxDepth(&root) << endl;
}

/*����һ�����������ж����Ƿ���һ����Ч�Ķ�����������
����һ��������������������������
�ڵ��������ֻ����С�ڵ�ǰ�ڵ������
�ڵ��������ֻ�������ڵ�ǰ�ڵ������
�������������������������Ҳ�Ƕ�����������*/
int treeDeep(TreeNode * root)
{
    if (root == nullptr) {
        return 0;
    }
    int left = treeDeep(root->left);
    int right = treeDeep(root->right);
    return (left > right ? left : right) + 1;
}

/*����һ�����������ж����Ƿ���һ����Ч�Ķ�����������
����һ��������������������������
�ڵ��������ֻ����С�ڵ�ǰ�ڵ������
�ڵ��������ֻ�������ڵ�ǰ�ڵ������
�������������������������Ҳ�Ƕ�����������*/
static TreeNode * pre = nullptr;
bool isValidBST(TreeNode * root)
{
    if (root == nullptr) {
        return true;
    }

    if (!isValidBST(root->left)) {
        return false;
    }

    if (pre != nullptr && root->val <= pre->val) {
        return false;
    }
    pre = root;

    if (!isValidBST(root->right)) {
        return false;
    }

    return true;
}

void testIsValidBST()
{
    TreeNode root(1);
    TreeNode node1(1);

    root.right = &node1;

    cout << isValidBST(&root) << endl;
}

/*����һ����������������Ƿ��Ǿ���ԳƵġ�
�Գƣ�
    1
   / \
  2   2
 / \ / \
3  4 4  3
���Գƣ�
    1
   / \
  2   2
   \   \
   3    3
*/
bool isSymmetric(TreeNode* left, TreeNode* right)
{
    if (left == nullptr || right == nullptr) {
        return left == right;
    }

    if (left->val != right->val) {
        return false;
    }

    return (isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left));
}
bool isSymmetric(TreeNode* root)
{
    if (root == nullptr) {
        return true;
    }

    return isSymmetric(root->left, root->right);
}

void testIsSymmetric()
{
    TreeNode root(1);
    TreeNode node1(2), node2(2), node3(3), node4(3), node5(4), node6(4);
    root.left = &node1;
    root.right = &node2;

    node1.left = &node3;
    node1.right = &node5;

    node2.left = &node6;
    node2.right = &node4;
    cout << isSymmetric(&root) << endl;
}

/*����һ���������������䰴��α����Ľڵ�ֵ�� �������أ������ҷ������нڵ㣩��*/
vector<vector<int>> levelOrder(TreeNode* root)
{
#if 0
    list<TreeNode*> thisLevel, nextLevel;
    vector<int> level;
    vector<vector<int>> ret;
    TreeNode * node = nullptr;
    if (root == nullptr) {
        return ret;
    }

    thisLevel.emplace_back(root);
    while (true) {
        while (!thisLevel.empty()) {
            node = thisLevel.front();
            thisLevel.erase(thisLevel.begin());
            level.push_back(node->val);
            if (node->left) {
                nextLevel.emplace_back(node->left);
            }
            if (node->right) {
                nextLevel.emplace_back(node->right);
            }
        }
        ret.push_back(level);
        level.clear();
        if (nextLevel.empty()) {
            break;
        }
        thisLevel = nextLevel;
        nextLevel.clear();
    }
    return ret;
#else
    vector<vector<int>> ans;
    if (!root) {
        return ans;
    }
    queue<TreeNode*> q;
    TreeNode* p;

    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        vector<int> a;

        for (int i = 0; i < size; i++) {
            p = q.front();
            a.push_back(p->val);
            q.pop();

            if (p->left) {
                q.push(p->left);
            }
            if (p->right) {
                q.push(p->right);
            }
        }
        ans.push_back(a);
    }
    return ans;
#endif
}

void testLevelOrder()
{
    TreeNode root(1);
    TreeNode node1(2), node2(2), node3(3), node4(3), node5(4), node6(4);
    root.left = &node1;
    root.right = &node2;

    node1.left = &node3;
    node1.right = &node5;

    node2.left = &node6;
    node2.right = &node4;

    auto ret = levelOrder(&root);
    for (auto & i : ret) {
        for (auto & j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

/*��һ�������������е��������飬ת��Ϊһ�ø߶�ƽ�������������
�����У�һ���߶�ƽ���������ָһ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������1��*/
TreeNode* sortedArrayToBST(vector<int>& nums, int low, int height)
{
    if (low > height) {
        return nullptr;
    }
    int mid = low + (height - low) / 2;
    TreeNode * node = new TreeNode(nums[mid]);
    node->left = sortedArrayToBST(nums, low, mid - 1);
    node->right = sortedArrayToBST(nums, mid + 1, height);
    return node;
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
    if (nums.empty()) {
        return nullptr;
    }

    int low = 0;
    int height = nums.size() - 1;
    return sortedArrayToBST(nums, low, height);
}

void testSortedArrayToBST()
{
    vector<int> nums = { -10,-3,0,5,9 };
    TreeNode * root = sortedArrayToBST(nums);
    auto ret = levelOrder(root);
    for (auto i : ret) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    //testMaxDepth();
    //testIsValidBST();
    //testIsSymmetric();
    //testLevelOrder();
    testSortedArrayToBST();
    system("pause");
    return 0;
}
#endif