#include "header.h"
class Solution {
public:
    int numSquares(int n) {
        auto square_nums = gengrate_square_num(n);
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        int ans = 0;
        int len = square_nums.size();
        for (int i = 2; i <= n; ++i) {
            int min_num = INT_MAX;
            for (int j = 0; j < len; ++j) {
                if (i - square_nums[j] < 0) break;
                min_num = min(dp[i - square_nums[j]] + 1, min_num);
            }
            dp[i] = min_num;
        }
        return dp[n];
    }
private:
    vector<int> gengrate_square_num(int n) {
        vector<int> square_nums;
        int sqr = sqrt(n);
        for (int i = 1; i <= n; ++i) {
            square_nums.emplace_back(i * i);
        }
        return square_nums;
    }
};

