#include "header.h"

//获取生成数组中的最大值

class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        if (n == 0) return 0;
        dp[1] = 1;
        int ans = dp[1];
        for (int i = 2; i <= n; ++i) {
            if (i & 1) dp[i] = dp[i / 2] + dp[i / 2 + 1];
            else dp[i] = dp[i / 2];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};