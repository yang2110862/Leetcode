#include "header.h"

class Solution {
private:
    void backtrack(vector<vector<int>>& ans, vector<int>& nums, int first) {
        if (first == nums.size()) {
            ans.emplace_back(nums);
            return;
        }
        for (int i = first; i < nums.size(); ++i) {
            swap(nums[first], nums[i]);
            backtrack(ans, nums, first + 1);
            swap(nums[first], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(ans, nums, 0);
        return ans;
    }
};