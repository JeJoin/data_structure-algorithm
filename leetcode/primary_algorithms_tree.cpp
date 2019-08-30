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
bool isSymmetric(TreeNode* root)
{

}

int main()
{
    //testMaxDepth();
    testIsValidBST();
    system("pause");
    return 0;
}
#endif