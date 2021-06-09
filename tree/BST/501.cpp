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
    vector<int> ans;
    int base, cnt, maxCnt;
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        if (root->val == base) {
            ++cnt;
        } else {
            cnt == 1;
            base = root->val;
        }
        if (cnt == maxCnt) {
            ans.push_back(base);
        }
        if (cnt > maxCnt) {
            maxCnt = cnt;
            ans = vector<int>{base};
        }
        inorder(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};