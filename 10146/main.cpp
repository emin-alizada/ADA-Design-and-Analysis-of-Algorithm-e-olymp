// C++
class TreeNode {
public:
    int val;
    TreeNode *left, *right, *parent;

    TreeNode(int x, TreeNode *prev = nullptr) : val(x), left(nullptr), right(nullptr), parent(prev) {}
};

TreeNode *Minimum(TreeNode *tree) {
    if (tree == nullptr) {
        return nullptr;
    } else {
        while (tree->left) {
            tree = tree->left;
        }
        return tree;
    }
}

TreeNode *Next(TreeNode *tree) {
    // If right subtree exists, next element is
    // min of right subtree
    if (tree->right != nullptr)
        return Minimum(tree->right);
    // otherwise, we need to move up until
    // we do not find a node which is left node of its parent
    TreeNode *Prev = tree->parent;
    while ((Prev != nullptr) && (tree == Prev->right)) {
        tree = Prev;
        Prev = Prev->parent;
    }
    return Prev;
}
