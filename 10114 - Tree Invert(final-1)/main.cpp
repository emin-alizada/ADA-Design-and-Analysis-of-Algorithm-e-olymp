class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* Invert(TreeNode* tree)
{
    if(!tree) return nullptr;
    TreeNode* t = new TreeNode(tree->val);
    t->left = Invert(tree->right);
    t->right = Invert(tree->left);
    return t;
}
