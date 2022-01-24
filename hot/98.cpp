#include "header.h"

//验证二叉搜索树

class Solution {
private:
    vector<int> arr;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        inorder(root);
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i - 1]) continue;
            else return false;
        }
        return true;
    }
};