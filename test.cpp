#include "header.h"
#include <ctime>
#include <cstring>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    // TreeNode(): val
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int main() {
    unordered_map<TreeNode*, vector<int>> mp;
    TreeNode* t = new TreeNode(3);
    TreeNode* tt = new TreeNode(3);
    mp[t].emplace_back(1);
    mp[t].push_back(2);
    cout << mp[t].size();
}
