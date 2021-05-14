#include "header.h"


class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                int temp1 = dp[j] * (i - j);
                int temp2 = (j + 1) * (i - j);
                dp[i] = max(dp[i], max(temp1, temp2));
            }
        }
        return dp[n - 1];
    }
};