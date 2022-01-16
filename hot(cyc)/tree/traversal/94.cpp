#include "header.h"

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) :  val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution1 {
private:
    vector<int> ans;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        auto curr = root;
        while (curr != nullptr || !st.empty()) {   //curr不空说明还有能加入到栈的点，st不空，说明还有没有输出的点
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            auto node = st.top();
            st.pop();
            ans.push_back(node->val);
            curr = node->right;
        }
        return ans;
    }
};