// C++
class TreeNode {
public:
    int val;
    TreeNode *left, *right, *parent;

    TreeNode(int x, TreeNode *prev = nullptr) : val(x), left(nullptr), right(nullptr), parent(prev) {}
};

TreeNode *Maximum(TreeNode *tree) {
    if (tree == nullptr) {
        return nullptr;
    } else {
        while (tree->right) {
            tree = tree->right;
        }
        return tree;
    }
}

TreeNode *Prev(TreeNode *tree) {
    if (tree->left != nullptr) {
        return Maximum(tree->left);
    }

    TreeNode *prev = tree->parent;

    while (prev != nullptr && tree == prev->left) {
        tree = prev;
        prev = prev->parent;
    }

    return prev;
}
