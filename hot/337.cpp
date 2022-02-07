#include "header.h"
//打家劫舍 III

//TTL
class Solution {
private:
    unordered_map<TreeNode*, int> notR;
    unordered_map<TreeNode*, int> R;
    int robRoot(TreeNode* root) {
        if (root == nullptr) return 0;
        int notRL = notR.count(root->left) ? notR[root->left] : notRobRoot(root->left);
        notR[root->left] = notRL;
        int notRR = notR.count(root->right) ? notR[root->right] : notRobRoot(root->right);
        notR[root->right] = notRR;
        return root->val + notRL + notRR;
    }
    int notRobRoot(TreeNode *root) {
        if (root == nullptr) return 0;
        int RL = R[root->left] ? R[root->left] : robRoot(root->left);
        R[root->left] = RL;
        int notRL = notR[root->left] ? notR[root->left] : notRobRoot(root->left);
        notR[root->left] = notRL;
        int RR = R[root->right] ? R[root->right] : robRoot(root->right);
        R[root->right] = RR;
        int notRR = notR[root->right] ? notR[root->right] : notRobRoot(root->right);
        notR[root->right] = notRR;
        int left = max(RL, notRL);
        int right = max(RR, notRR);
        return left + right;
    }
public:
    int rob(TreeNode* root) {
        return max(robRoot(root), notRobRoot(root));
    }
};