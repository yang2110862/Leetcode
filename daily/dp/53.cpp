#include "header.h"


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int dp = nums[0];
        for (int i = 1; i < n; ++i) {
            dp = max(dp + nums[i], nums[i]);
            ans = max(dp, ans);
        }
        return ans;
    }
};