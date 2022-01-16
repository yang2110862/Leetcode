#include "header.h"

//买卖股票的最佳时机 II

//一维dp
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp1(n);
        vector<int> dp0(n);
        dp0[0] = 0;
        dp1[0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp0[i] = max(dp0[i - 1], dp1[i - 1] + prices[i]);
            dp1[i] = max(dp1[i - 1], dp0[i - 1] - prices[i]);
        }
        return dp0[n - 1];
    }
};

//1维到0维

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp0 = 0;
        int dp1 = -prices[0];
        for (int i = 1; i < n; ++i) {
            int newdp0 = max(dp0, dp1 + prices[i]);
            int newdp1 = max(dp1, dp0 - prices[i]);
            dp0 = newdp0;
            dp1 = newdp1;
        }
        return dp0;
    }
};