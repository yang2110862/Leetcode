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
private:
    void backtrace(vector<string>& ans, TreeNode* root, string& str) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            ans.push_back(str + to_string(root->val));
            return;
        }
        string temp = str + to_string(root->val) + "->";
        backtrace(ans, root->left, temp);
        backtrace(ans, root->right, temp);
        return;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string str;
        backtrace(ans, root, str);
        return ans;
    }
};