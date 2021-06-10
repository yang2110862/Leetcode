#include "header.h"

//组合背包
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 1);
        int n = coins.size();
        dp[0] = 1;
        for (auto coin : coins) {
            for (int i = 1; i <= coin; ++i) {
                dp[i] = dp[i] + dp[i - coin];
            }
        }
        return dp[amount];
    }
};