#include "header.h"

//对称二叉树

class Solution {
private:
    bool check(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return left->val == right->val && check(left->left, right->right) && check(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {  
        return check(root, root);
    }
};