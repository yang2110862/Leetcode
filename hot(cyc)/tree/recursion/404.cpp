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
    bool isLeaf(TreeNode* root) {
        if (!root) return false;
        return !root->left && !root->right;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        if (!root) return 0;
        if (isLeaf(root->left)) return root->left->val + sumOfLeftLeaves(root->right);
        else return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};