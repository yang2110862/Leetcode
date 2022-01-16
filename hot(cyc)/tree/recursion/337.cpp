#include "header.h"

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) :  val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

struct SubTreeStatus {
    int selected;
    int not_selected;
};
class Solution {
private:
    SubTreeStatus dfs(TreeNode* root) {
        if (root == nullptr) return {0, 0};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        int selected = root->val + l.not_selected + r.not_selected;
        int not_selected = max(l.not_selected, l.selected) + max(r.not_selected, r.selected);
        return {selected, not_selected};
    }
public:
    int rob(TreeNode* root) {
        auto status = dfs(root);
        return max(status.not_selected, status.selected);
    }
};