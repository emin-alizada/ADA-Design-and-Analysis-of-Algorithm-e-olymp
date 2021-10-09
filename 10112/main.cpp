#include <cmath>
#include <opencl-c.h>

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int Height(TreeNode *tree)
{
    if (tree == nullptr) {
        return 0;
    }
    if (tree->left == nullptr && tree->right == nullptr) {
        return 1;
    } else {
        int left = Height(tree->left);
        int right = Height(tree->right);
        if (left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        }

        return max(left, right) + 1;
    }
}

bool isBalanced(TreeNode* root)
{
    return Height(root) != -1;
}
