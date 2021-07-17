#include "header.h"
//连续子数组的最大和 DP
class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        int ans = nums[0];
        for (int i = 1; i <= n; ++i) {
            dp[i] = max(dp[i - 1] + nums[i - 1], nums[i - 1]);
            ans = max(dp[i], ans);
        }
        return ans;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int pre = 0;
        int ans = nums[0];
        for (int i = 1; i <= n; ++i) {
            pre = max(pre + nums[i - 1], nums[i - 1]);
            ans = max(pre, ans);
        }
        return ans;
    }
};


