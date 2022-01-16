#include "header.h"

//注意边界 k取0或很大的时候
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k == 0) return 0;
        if (k * 2 > n) {
            k = n / 2;
        }
        int ans = 0;
        vector<int> dp(2 * k, 0);
        vector<int> dp_temp(2 * k);
        for (int i = 0; i < 2 * k; i += 2) {
            dp[i] = -prices[0];
        }
        for (int i = 1; i < n; ++i) {
            dp_temp[0] = max(dp[0], -prices[i]);
            for (int j = 2; j < 2 * k; j += 2) {
                dp_temp[j] = max(dp[j], dp[j - 1] - prices[i]);
            }
            for (int j = 1; j < 2 * k; j += 2) {
                dp_temp[j] = max(dp[j], dp[j - 1] + prices[i]);
            }
            for (int j = 0; j < 2 * k; ++j) {
                dp[j] = dp_temp[j];
            }
        }
        for (int i = 1; i < 2 * k; ++i) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<int> prices{1,3};
    int k = 0;
    cout << test.maxProfit(k, prices);
    return 0;
}