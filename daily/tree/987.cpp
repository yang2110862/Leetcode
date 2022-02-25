#include "header.h"
#include <functional>
#include <cfloat>
#include <climits>
//二叉树的垂序遍历


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
    vector<tuple<int, int, int>> nodes;
    void dfs(TreeNode* node, int col, int row) {
        if (node == nullptr) return;
        nodes.emplace_back(col, row, node->val);
        dfs(node->left, col - 1, row + 1);
        dfs(node->right, col + 1, row + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        sort(nodes.begin(), nodes.end());
        vector<vector<int>> ans;
        int lastCol = INT_MAX;
        for (auto& node : nodes) {
            if (get<0>(node) != lastCol) {
                ans.emplace_back();
            }
            ans.back().push_back(get<2>(node));
            lastCol = get<0>(node);
        }
        return ans;
    }
};