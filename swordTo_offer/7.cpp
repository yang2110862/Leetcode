#include "header.h"

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
private:
    unordered_map<int, int> mp;
    vector<int> preorder;
    TreeNode* recur(int root, int left, int right) {
        if (left > right) return nullptr;
        TreeNode* ans = new TreeNode(preorder[root]);
        int mid = mp[preorder[root]];
        ans->left = recur(root + 1, left, mid - 1);
        ans->right = recur(mid - left + root + 1, mid + 1, right);
        return ans;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        for (int i = 0; i < inorder.size(); ++i) {
            mp[inorder[i]] = i;
        }
        return recur(0, 0, preorder.size() - 1);
    }
};