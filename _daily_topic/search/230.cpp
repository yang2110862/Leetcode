#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution1 {
private:
    int ans;
    void inorder(TreeNode* root, int& i, int k) {
        if (root == nullptr) return;
        inorder(root->left, i, k);
        if (i == k) {
            ans = root->val;
            i = i + 1;
            return;
        } else {
            i = i + 1;
        }
        inorder(root->right, i, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int i = 1;
        inorder(root, i, k);
        return ans;
    }
};


//迭代法
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> sk;
        while (!sk.empty() || root) {
            while (root) {
                sk.push(root);
                root = root->left;
            }
            root = sk.top();
            sk.pop();
            --k;
            if (k == 0) return root->val;
            root = root->right;
        }
        return -1;
    }
};