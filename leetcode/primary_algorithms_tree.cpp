#include <common.h>
#if PRIMARY_ALGORITHMS_TREE
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
说明: 叶子节点是指没有子节点的节点。*/
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

/*给定一个二叉树，判断其是否是一个有效的二叉搜索树。
假设一个二叉搜索树具有如下特征：
节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。*/
int treeDeep(TreeNode * root)
{
    if (root == nullptr) {
        return 0;
    }
    int left = treeDeep(root->left);
    int right = treeDeep(root->right);
    return (left > right ? left : right) + 1;
}

/*给定一个二叉树，判断其是否是一个有效的二叉搜索树。
假设一个二叉搜索树具有如下特征：
节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。*/
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

/*给定一个二叉树，检查它是否是镜像对称的。
对称：
    1
   / \
  2   2
 / \ / \
3  4 4  3
不对称：
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

/*给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。*/
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

/*将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。*/
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