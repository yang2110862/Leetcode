#include "header.h"

//二叉树的前序遍历

class Solution1 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        while (!stk.empty() || root) {
            while (root) {
                ans.push_back(root->val);
                stk.push(root);
                root = root->left;
            }
            if (!stk.empty()) {
                root = stk.top();
                stk.pop();
                root = root->right;
            }
        }
        return ans;
    }
};

//原地

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                TreeNode* next = curr->left;
                TreeNode* p = next;
                while (p->right) {
                    p = p->right;
                }
                p->right = curr->right;
                curr->right = next;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};