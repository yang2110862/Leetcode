#include "header.h"
#include <functional>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        int ans = -1;
        int root_value = root->val;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) return;
            if (ans != -1 && root->val >= ans) return;
            if (root->val > root_value) ans = root->val;
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root);
        return ans;
    }
};