#include "header.h"

//二叉树的最近公共祖先


class Solution {
private:   
    unordered_map<TreeNode*, TreeNode*> fathers;
    unordered_set<TreeNode*> st;
    void traverse(TreeNode* root) {
        if (root == nullptr) return;
        if (root->left) fathers[root->left] = root;
        if (root->right) fathers[root->right] = root;
        traverse(root->left);
        traverse(root->right);
        return;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        traverse(root);
        st.insert(p);
        st.insert(q);
        while (p != q) {
            p = fathers[p];
            q = fathers[q];
            if (st.count(p)) return p;
            if (st.count(q)) return q;
            if (p)  st.insert(p);
            if (q)  st.insert(q);
        }
        return p;
    }
};