#include "header.h"

//二叉树展开为链表

class Solution {
private:
    vector<TreeNode*> arr;
    void preOrder(TreeNode* root) {
        if (!root) return;
        arr.push_back(root);
        preOrder(root->left);
        preOrder(root->right);
    }
public:
    void flatten(TreeNode* root) {
        preOrder(root);
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            arr[i - 1]->left = nullptr;
            arr[i - 1]->right = arr[i];
        }
    }
};