#include "header.h"

//最大子数组和

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            if (dp[i] > ans) {
                ans = dp[i];
            }
        }
        return ans;
    }
};