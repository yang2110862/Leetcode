#include "header.h"

//买卖股票的最佳时机

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minPrice = INT_MAX;
        int n = prices.size();
        for (int i = 0; i < n; ++i) {
            ans = max(ans, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return ans;
    }
};