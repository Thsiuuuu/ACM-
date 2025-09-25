#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* trimBST(TreeNode* cur, int low, int high) {
    if (cur == nullptr) {
        return nullptr;
    }
    if (cur->val < low) {
        return trimBST(cur->right, low, high);
    }
    if (cur->val > high) {
        return trimBST(cur->left, low, high);
    }
    // 当前节点值在范围内，修剪左右子树
    cur->left = trimBST(cur->left, low, high);
    cur->right = trimBST(cur->right, low, high);
    return cur;
}