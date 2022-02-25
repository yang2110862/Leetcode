#include "header.h"

//1维dp
class Solution1 {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
// 降1维到0维  运用滚动数组思想
class Solution {
public:
    int climbStairs(int n) {
        int p = 1;
        int q = 1;
        int ans = 1;
        for (int i = 2; i <= n; ++i) {
            ans = p + q;
            p = q;
            q = ans;
        }
        return ans;
    }
};