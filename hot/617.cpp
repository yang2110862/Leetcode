#include "header.h"

//合并二叉树

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return nullptr;
        }
        TreeNode* ans;
        int v1 = root1 == nullptr ? 0 : root1->val;
        int v2 = root2 == nullptr ? 0 : root2->val;
        ans = new TreeNode(v1 + v2);
        ans->left = mergeTrees(root1 == nullptr ? nullptr : root1->left, root2 == nullptr ? nullptr : root2->left);
        ans->right = mergeTrees(root1 == nullptr ? nullptr : root1->right, root2 == nullptr ? nullptr : root2->right);
        return ans;
    }
};