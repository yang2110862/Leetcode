#include "header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp00 = -prices[0];  //第一次持股
        int dp01 = -prices[0];   //第二次持股
        int dp10 = 0;   //第一次卖股
        int dp11 = 0;   //第二次卖股
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            int new_dp00 = max(dp00, -prices[i]);
            int new_dp01 = max(dp01, dp10 -prices[i]);
            int new_dp10 = max(dp10, dp00 + prices[i]);
            int new_dp11 = max(dp11, dp01 + prices[i]);
            dp00 = new_dp00;
            dp01 = new_dp01;
            dp10 = new_dp10;
            dp11 = new_dp11;
        }
        return max(dp10, dp11);
    }
};
