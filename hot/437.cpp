#include "header.h"

//路径总和 III

class Solution {
private:
    int ans;
    void search(TreeNode* node, int target, int sum) {
        if (node == nullptr) {
            return;
        }
        sum += node->val;
        if (sum == target) ans++;
        search(node->left, target, sum);
        search(node->right, target, sum);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        queue<TreeNode*> q;
        if (!root) return 0;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                search(node, targetSum, 0);
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ans;
    }
};

int main() {
    Solution test;
    TreeNode* node = new TreeNode(5);
    node->left = new TreeNode(3);
    cout << test.pathSum(node, 8);
}