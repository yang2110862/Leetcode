#include "header.h"

//1、背包 2、记录       2是难点
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<int> dp(target + 1, INT_MIN);
        dp[0] = 0;
        for (auto num : cost) {
            for (int i = num; i <= target; ++i) {
                dp[i] = max(dp[i], dp[i - num] + 1);
            }
        }
        if (dp[target] < 0) return "0";
        string ans;
        int j = target;
        for (int i = 8;i >= 0; --i) {
            while(j >= cost[i] && dp[j] == dp[j - cost[i]] + 1) {
                ans += '1' + i;
                j -= cost[i];
            }
        }
        return ans;
    }
};
