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
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        int left_height = height(root->left);
        int right_height = height(root->right);
        if (left_height == -1 || right_height == -1 || abs(left_height - right_height) > 1) {
            return -1;
        } else {
            return max(left_height, right_height) + 1;
        }
    }
public:
    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
    }
};