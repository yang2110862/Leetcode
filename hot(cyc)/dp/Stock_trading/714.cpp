#include "header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int dp0 = -prices[0];
        int dp1 = 0;
        int new_dp0, new_dp1;
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            new_dp0 = max(dp1 - prices[i], dp0);
            new_dp1 = max(dp0 + prices[i] - fee, dp1);
            dp0 = new_dp0;
            dp1 = new_dp1;
            ans = max(max(dp0, dp1), ans);
        }
        return ans;
    }
};