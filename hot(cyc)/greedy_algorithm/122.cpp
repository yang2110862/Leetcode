#include "header.h"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int ans = 0;
        int n = prices.size();
        for (int i = 1; i < n; ++i) {
            int profit = prices[i] - prices[buy];
            if (profit > 0) {
                ans += profit;
                buy = i;
            }
            if (prices[i] < prices[buy]) {
                buy = i;
            }
        }
        return ans;
    }
};