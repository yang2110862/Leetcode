#include "header.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = 1;
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            int max_len = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    max_len = max(max_len, dp[j] + 1);
                }
            }
            dp[i] = max_len;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};