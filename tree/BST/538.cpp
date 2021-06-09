#include "header.h"

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) :  val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
//可以用上反序中序遍历（知道就行）
class Solution {
private:
    vector<int> arr;
    unordered_map<int, int> mp;
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    void creatMap() {
        int sum = 0;
        for (auto x : arr) {
            sum += x;
            mp[x] = sum;
        }
    }
    void updataValue(TreeNode* root) {
        if (root == nullptr) return;
        updataValue(root->left);
        updataValue(root->right);
        root->val = mp[root->val];
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        inorder(root);
        reverse(arr.begin(), arr.end());
        creatMap();
        updataValue(root);
        return root;
    }
};
