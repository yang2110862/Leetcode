#include "header.h"

class Solution1 {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (auto x : nums) {
            sum += x;
        }
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            int value = nums[i - 1];
            for (int j = 0; j <= target; ++j) {
                if (value <= j) {
                    dp[i][j] = dp[i - 1][j - value] | dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][target];
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (auto x : nums) {
            sum += x;
        }
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            int value = nums[i - 1];
            for (int j = 0; j <= target; ++j) {
                if (value <= j) {
                    dp[i][j] = dp[i - 1][j - value] | dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][target];
    }
};

