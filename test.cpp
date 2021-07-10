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
    vector<int> vec{1,3,5,7,9};
    vector<int> vec2{9,7,5,3,1};
    cout << *lower_bound(vec.begin(), vec.end(), 3);
}
