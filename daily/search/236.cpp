#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//存储父节点
class Solution {
private:
    unordered_map<TreeNode*, TreeNode*> par;
    unordered_map<TreeNode*, bool> visited;
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        if (root->left) {
            par[root->left] = root;
            dfs(root->left);
        }
        if (root->right) {
            par[root->right] = root;
            dfs(root->right);
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root);
        while (p != nullptr) {
            visited[p] = true;
            p = par[p];
        }
        while (q != nullptr) {
            if (visited[q]) {
                return q;
            }
            q = par[q];
        }
        return nullptr;
    }
};

//递归 yyds

class Solution {
public:
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
            ans = root;
        } 
        return lson || rson || (root->val == p->val || root->val == q->val);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};
