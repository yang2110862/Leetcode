#include "header.h"

//二叉树中的最大路径和

class Solution {
private:
    int ans = 0;
    unordered_map<TreeNode*, int> mp;
    int maxPathAsEnd(TreeNode* root) {
        if (!root) return 0;
        if (mp.count(root)) return mp[root];
        int res = root->val + max(max(0, maxPathAsEnd(root->left)), max(0, maxPathAsEnd(root->right)));
        mp[root] = res;
        return res;
    }
    void traverse(TreeNode* root) {
        if (!root) return;
        ans = max(ans, max(0, maxPathAsEnd(root->left)) + max(0, maxPathAsEnd(root->right)) + root->val);
        traverse(root->left);
        traverse(root->right);
    }
public:
    int maxPathSum(TreeNode* root) {
        ans = root->val;
        traverse(root);
        return ans;
    }
};