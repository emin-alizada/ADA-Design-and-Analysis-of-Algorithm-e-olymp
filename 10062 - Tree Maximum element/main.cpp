class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *Maximum(TreeNode *tree) {
    if (tree == NULL) {
        return NULL;
    } else {
        while (tree->right) {
            tree = tree->right;
        }
        return tree;
    }
}