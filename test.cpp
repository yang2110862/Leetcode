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
    string s = "3";
    cout << stoi(s);
    return 0;
}