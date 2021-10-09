int SumLeaves(TreeNode *tree) {
    int sum = 0;

    if(tree->left == nullptr && tree->right == nullptr && tree != nullptr) {
        sum = tree->val;
    }

    if (tree->left != nullptr) {
        if (tree->left->left == nullptr && tree->left->right == nullptr) {
            sum += tree->left->val;
        } else {
            sum += SumLeaves(tree->left);
        }
    }

    if(tree->right != nullptr) {
        if (tree->right->left == nullptr && tree->right->right == nullptr) {
            sum += tree->right->val;
        } else {
            sum += SumLeaves(tree->right);
        }
    }
    return sum;
}