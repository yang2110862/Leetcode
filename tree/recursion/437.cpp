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
    unordered_map<int, int> mp;
private:
    int dfs(TreeNode* root, int targetSum, int pre) {
        if (!root) return 0;
        int sum = pre + root->val;
        int ans = 0;
        if (mp.find(sum - targetSum) != mp.end()) ans += mp[sum - targetSum];
        ++mp[sum];
        ans += dfs(root->left, targetSum, sum);
        ans += dfs(root->right, targetSum, sum);
        --mp[sum];
        return ans;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        return dfs(root, targetSum, 0);
    }
};