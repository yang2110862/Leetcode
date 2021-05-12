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
    vector<TreeNode*> generateTrees(int low, int high) {
        if (low > high) {
            return { nullptr }; //!!不能返回{}  ，空指针也是指针
        }
        vector<TreeNode*> ans;
        for (int i = low; i <= high; ++i) {
            vector<TreeNode*> left = generateTrees(low, i - 1);
            vector<TreeNode*>  right = generateTrees(i + 1, high);
            for (auto& j : left) {
                for (auto& k : right) {
                    TreeNode* temp = new TreeNode(i);
                    temp->left = j;
                    temp->right = k;
                    ans.emplace_back(temp);    //ans里面存放的是指针，所以不能释放temp的空间，不然ans里面的指针也会被free掉
                    //delete temp;
                }
            }
        }
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (!n) {
            return {};
        }
        return generateTrees(1, n);
    }
};