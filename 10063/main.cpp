TreeNode *Find(TreeNode *tree, int element) {
    if (tree == NULL) return NULL;
    if (element == tree->val) return tree;
    if (element < tree->val) return Find(tree->left, element);
    else return Find(tree->right, element);
}