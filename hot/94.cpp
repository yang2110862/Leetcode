#include "header.h"
//二叉树的中序遍历

//递归
class Solution {
private:
    vector<int> ans;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
};

//迭代
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ans;
        while (!stk.empty() || root) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            if (!stk.empty()) {
                TreeNode* temp = stk.top();
                stk.pop();
                ans.push_back(temp->val);
                root = temp->right;
            }
        }
        return ans;
    }
};