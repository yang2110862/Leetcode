#include "header.h"

//子集

class Solution {
private:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, int index, int n, vector<int> combination) {
        if (index == n) {
            ans.push_back(combination);
            return;
        }
        backtrack(nums, index + 1, n, combination);
        combination.push_back(nums[index]);
        backtrack(nums, index + 1, n, combination);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> combination;
        backtrack(nums, 0, n, combination);
        return ans;
    }
};