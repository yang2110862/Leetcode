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
    int depth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left) return depth(root->right) + 1;
        if (!root->right) return depth(root->left) + 1;
        return min(depth(root->left), depth(root->right)) + 1;
    }
public:
    int minDepth(TreeNode* root) {
        return depth(root);
    }
};