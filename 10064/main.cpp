#include "iostream"

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int Sum(TreeNode *tree)
{
    int sum = 0;

    if (tree != nullptr) {
        sum += Sum(tree->left);
        sum += Sum(tree->right);
        sum += tree->val;
    }

    return sum;
}
