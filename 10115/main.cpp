//
// Created by Emin Alizade on 09.10.21.
//
// C++
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool compare(TreeNode* left, TreeNode* right){
    if(!left && !right) return true;
    if(!left || !right) return false;
    if(left->val == right->val) return compare(left->left, right->right) && compare(left->right, right->left);
    return false;
}

bool isSymmetric(TreeNode *tree)
{
    return compare(tree->left, tree->right);
}
