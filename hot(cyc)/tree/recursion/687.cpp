#include "header.h"

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) :  val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int ans = 0;
    int arrow_len(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = 0, right = 0;
        if (root->left && root->left->val == root->val) left = arrow_len(root->left);
        if (root->right && root->right->val == root->val) right = arrow_len(root->right);
        return max(left, right) + 1;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = 0, right = 0;
        if (root->left && root->left->val == root->val) left = arrow_len(root->left);
        if (root->right && root->right->val == root->val) right = arrow_len(root->right);
        int res = left + right;
        ans = max(res, max(longestUnivaluePath(root->left), longestUnivaluePath(root->right)));
        return ans;
    }
};
