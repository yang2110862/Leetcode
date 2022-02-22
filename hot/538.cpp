#include "header.h"

//把二叉搜索树转换为累加树

class Solution {
private:
    unordered_map<int, int> sum;
    void preorder1(TreeNode* root) {
        if (root == nullptr) return;
        sum[root->val] = root->val;
        preorder1(root->left);
        preorder1(root->right);
        return;
    }
    void preorder2(TreeNode* root) {
        if (root == nullptr) return;
        for (auto it : sum) {
            if (it.first < root->val)
                sum[it.first] += root->val;
        }
        preorder2(root->left);
        preorder2(root->right);
        return;
    }
    void preorder3(TreeNode* root) {
        if (root == nullptr) return;
        root->val = sum[root->val];
        preorder3(root->left);
        preorder3(root->right);
        return;
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        preorder1(root);
        preorder2(root);
        preorder3(root);
        return root;
    }
};

int main() {
    Solution test;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    auto x = test.convertBST(root);
}