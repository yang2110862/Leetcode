#include "header.h"

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        int x = preorder[0];
        preorder.erase(preorder.begin());
        int index;
        for (int i = 0; i < inorder.size(); ++i) {
            if (inorder[i] == x) {
                index = i;
                inorder.erase(inorder.begin() + i);
            }
        }
        if (index != 0) {
            root->
        }
    }
};