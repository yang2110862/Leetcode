#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int maxPathAsEnd(TreeNode* root) {
        if (root == nullptr) return 0;
        int ans = root->val;
        int left = maxPathAsEnd(root->left);
        int right = maxPathAsEnd(root->right);
        ans = max(max(ans, ans + left), ans + right);
        return ans;
    }
    void inorder(TreeNode* root, int& maxValue) {
        if (root == nullptr) return;
        inorder(root->left, maxValue);
        maxValue = max(maxValue, max(maxPathAsEnd(root), root->val + maxPathAsEnd(root->left) + maxPathAsEnd(root->right)));
        inorder(root->right, maxValue);
    }
public:
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return -1;
        int ans = root->val;
        inorder(root, ans);
        return ans;
    }
};