#include "header.h"

class Solution {
private:
    vector<int> arr;
    void generate_arr(int n) {
        for (int i = 1; i * i <= n; ++i) {
            arr.push_back(i * i);
        }
    }
public:
    int numSquares(int n) {
        generate_arr(n);
        int len = arr.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (auto num : arr) {
            for (int i = num; i <= n; ++i) {
                if (dp[i - num] != INT_MAX) dp[i] = min(dp[i], dp[i - num] + 1);
            }
        }
        return dp[n];
    }
};