#include "iostream"

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void PostOrder(TreeNode *tree)
{
    if (tree != nullptr) {
        PostOrder(tree->left);
        PostOrder(tree->right);
        printf("%d ", tree->val);
    }
}
