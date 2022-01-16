#include "header.h"
#include <climits>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int m = INT_MAX;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, prices[i] - m);
            m = min(prices[i], m);
        }
        return ans;
    }
};