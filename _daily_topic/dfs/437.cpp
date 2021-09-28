#include "header.h"
// 437. 路径总和 III
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//dfs
class Solution {
private:
    int dfs(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;
        int sum = 0;
        int val = root->val;
        if (val == targetSum) sum += 1;
        sum += dfs(root->left, targetSum - val);
        sum += dfs(root->right, targetSum - val);
        return sum;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        if (root == nullptr) return 0;
        sum += dfs(root, targetSum);
        sum += pathSum(root->left, targetSum);
        sum += pathSum(root->right, targetSum);
        return sum;
    }
};