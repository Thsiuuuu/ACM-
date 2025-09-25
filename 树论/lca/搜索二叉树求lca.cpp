#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root->val != p->val && root->val != q->val) {
        if (std::min(p->val, q->val) < root->val && root->val < std::max(p->val, q->val)) {
            break;
        }
        root = root->val < std::min(p->val, q->val) ? root->right : root->left;
    }
    return root;
}