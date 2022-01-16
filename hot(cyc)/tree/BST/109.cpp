#include "header.h"
struct ListNode {
   int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


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
TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        int n = nums.size();
        int mid = n / 2;
        vector<int> left_nums;
        vector<int> right_nums;
        for (int i = 0; i < mid; ++i) {
            left_nums.push_back(nums[i]);
        }
        for (int i = mid + 1; i < n; ++i) {
            right_nums.push_back(nums[i]);
        }
        TreeNode* root = new TreeNode;
        root->val = nums[mid];
        root->left = sortedArrayToBST(left_nums);
        root->right = sortedArrayToBST(right_nums);
        return root;
    }
private:
vector<int> to_vector(ListNode* head) {
    vector<int> ans;
    while (head != nullptr) {
        ans.push_back(head->val);
        head = head->next;
    }
    return ans;
}
public:
    TreeNode* sortedListToBST(ListNode* head) {
        auto arr = to_vector(head);
        return sortedArrayToBST(arr);
    }
};