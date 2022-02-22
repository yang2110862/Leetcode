#include "header.h"
//二叉树的直径

class Solution {
private:
    int depth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(depth(root->left) + depth(root->right), 
        max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
};