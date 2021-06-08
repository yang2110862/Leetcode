#include "header.h"

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto num : nums) sum += num;
        int n = nums.size();
        if ((sum + target) & 1) return 0;
        int new_target = (sum + target) / 2;
        vector<int> dp(new_target + 1); 
        dp[0] = 1;
        for (auto num : nums) {
            for (int i = new_target; i >= num; --i) {
                dp[i] = dp[i] + dp[i - num];
            }
        }
        return dp[new_target];
    }
};