#include "header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp0, dp1, dp2;
        dp0 = -prices[0];
        dp1 = 0;
        dp2 = 0;
        for (int i = 1; i < n; ++i) {
            int new_dp0 = max(dp0, dp1 - prices[i]);
            int new_dp1 = max(dp1, dp2);
            int new_dp2 = dp0 + prices[i];
            dp0 = new_dp0;
            dp1 = new_dp1;
            dp2 = new_dp2;
        }
        int ans = max(max(dp0, dp1), dp2);
        return ans;
    }
};
