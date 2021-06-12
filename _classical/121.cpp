#include "header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int ans = 0;
        for (auto price : prices) {
            ans = max(price - min_price, ans);
            min_price = min(min_price, price);
        }
        return ans;
    }
};