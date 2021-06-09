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
    vector<int> arr;
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        int ans = INT_MAX;
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            ans = min(arr[i] - arr[i - 1], ans);
        }
        return ans;
    }
};