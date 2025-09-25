#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }
    TreeNode* l = lca(root->left, p, q);
    TreeNode* r = lca(root->right, p, q);
    if (l != nullptr && r != nullptr) {
        return root;
    }
    if (l == nullptr && r == nullptr) {
        return nullptr;
    }
    return l != nullptr ? l : r;
    
}