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