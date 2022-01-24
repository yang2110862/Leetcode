#include "header.h"

//从前序与中序遍历序列构造二叉树


class Solution {
private:
    unordered_map<int, int> index;
    TreeNode* build(const vector<int>& preorder, const vector<int>& inorder, int preLeft, 
    int preRight, int inLeft, int inRight) {
        if (inLeft > inRight) return nullptr;
        int rootIndex = preorder[preLeft];
        int inIndex = index[rootIndex];
        TreeNode* root = new TreeNode(rootIndex);
        int leftLen = inIndex - inLeft;
        int rightLen = inRight - inIndex;
        root->left = build(preorder, inorder, preLeft + 1, preLeft + leftLen, inLeft, inIndex - 1);
        root->right = build(preorder, inorder, preLeft + leftLen + 1, preRight, inIndex + 1, inRight);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};