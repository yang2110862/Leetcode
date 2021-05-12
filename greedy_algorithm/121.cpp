#include "header.h"
class Solution {   
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int ans = 0;
        int n = prices.size();
        int soFarMin = prices[0];
        for (int i = 1; i < n; ++i) {
            ans = max(ans, prices[i] - soFarMin);
            soFarMin = min(soFarMin, prices[i]);
        }
        return ans;
    }
};