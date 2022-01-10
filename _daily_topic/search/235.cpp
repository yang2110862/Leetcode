#include "header.h"

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr);
        if (p->val > q->val) {
            TreeNode* temp = p;
            p = q;
            q = temp;
        }
        while (root) {
            if (root->val >= p->val && root->val <= q->val) {
                return root;
            } else if (root->val <= p->val) {
                root = root->right;
            } else {
                root = root->left;
            }
        }      
        return nullptr;
    }
};