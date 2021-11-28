// C++
#include "iostream"

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void PreOrder(TreeNode *tree)
{
    if (tree != nullptr) {
        printf("%d ", tree->val);

        PreOrder(tree->left);
        PreOrder(tree->right);
    }
}
