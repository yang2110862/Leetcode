#include "header.h"


class Solution {
private:
    unordered_map<TreeNode*, TreeNode *> fa;
    unordered_map<int, TreeNode*> mp;
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        mp[descriptions[0][0]] = new TreeNode(descriptions[0][0]);
        if (descriptions[0][2] == 1) {
            mp[descriptions[0][0]]->left = new TreeNode(descriptions[0][1]);
        } else {
            mp[descriptions[0][0]]->right = new TreeNode(descriptions[0][1]);
        }
        TreeNode* ans = mp[descriptions[0][0]];
        for (auto des : descriptions) {
            int f = des[0];
            int c = des[1];
            if (!mp.count(f)) {
                mp[f] = new TreeNode(f);
            }
            if (!mp.count(c)) {
                mp[c] = new TreeNode(c);
            }
            if (des[2] == 1) {
                mp[f]->left = mp[c];
            } else {
                mp[f]->right = mp[c];
            }
            fa[mp[c]] = mp[f]; 
        }
        while (fa[ans]) {
            ans = fa[ans];
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<vector<int>> arr{{20, 15, 1}, {20, 17, 0}};
    auto x = test.createBinaryTree(arr);
}