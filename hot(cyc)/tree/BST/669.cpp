#include "header.h"

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) :  val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
//如果当前节点符合要求，则修剪了左右节点后返回该节点，如果该节点不符合要求，则修剪，使符合要求
//如果该节点大了，则root—>right全不符合要求，则返回修剪后的左节点。
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return root;
        if (root->val > high) return trimBST(root->left, low, high);
        if (root->val < low) return trimBST(root->right, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};