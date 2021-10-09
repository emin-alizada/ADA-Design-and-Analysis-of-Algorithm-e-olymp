#include "iostream"

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void InOrder(TreeNode *tree)
{
    if (tree != nullptr) {
        InOrder(tree->left);

        printf("%d ", tree->val);

        InOrder(tree->right);
    }
}
