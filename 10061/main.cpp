class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *Minimum(TreeNode *tree) {
    if (tree == NULL) {
        return NULL;
    } else {
        while (tree->left) {
            tree = tree->left;
        }
        return tree;
    }
}