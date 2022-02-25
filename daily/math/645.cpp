#include "header.h"

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int loss, dup;
        int n = nums.size();
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) dup = nums[i];
            if (nums[i] == nums[i + 1] - 2) loss = nums[i] + 1;
        }
        if (nums[0] != 1) loss = 1;
        if (nums[n - 1] != n) loss = n;
        ans.push_back(dup);
        ans.push_back(loss);
        return ans;
    }
};