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
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int n = arr.size();
        int l = 0, r = n - 1;
        while(l < r) {
            if (arr[l] + arr[r] == k) return true;
            else if (arr[l] + arr[r] < k) ++l;
            else --r;
        }
        return false;
    }
};
