#include "header.h"

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) :  val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution1 {
private:
    vector<int> res;
    void preorder(TreeNode* root) {
        if (root == nullptr) return;
        res.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return res;
    }   
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            res.push_back(node->val);
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
        return res;
    }
};