// C++
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumLeft(TreeNode *tree) {
    int sum = 0;
    if (tree->left != nullptr) {
        if (tree->left->left == nullptr && tree->left->right == nullptr) {
//            Vertex is a leaf if both its left and right child are NULL
            sum += tree->left->val;
        } else {
            sum += sumLeft(tree->left);
        }
    }

    if(tree->right != nullptr) {
        sum += sumLeft(tree->right);
    }
    return sum;
}