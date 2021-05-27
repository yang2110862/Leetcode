#include "header.h"

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto num : nums) sum += num;
        if ((target + sum) & 1) return 0;
        target = (sum + target) / 2;
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (auto num : nums) {
            for (int i = target; i >= num; --i) {   //注意i要大于等于num,不然越界，同时也剪了枝
                dp[i] = dp[i] + dp[i - num];
            }
        }
        return dp[target];
    }
};