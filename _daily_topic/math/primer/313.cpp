#include "header.h"
#include <climits>
//超级丑数  dp解法
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long> dp(n);
        dp[0] = 1;
        int m = primes.size();
        vector<long> p(m, 0);
        for (int i = 1; i < n; ++i) {
            long min_num = INT_MAX;
            for (int j = 0; j < m; ++j) {
                long loc = dp[p[j]] * primes[j];
                min_num = min(min_num, loc);
            }
            for (int j = 0; j < m; ++j) {
                if (dp[p[j]] * primes[j] == min_num) ++p[j];
            }
            dp[i] = min_num;
        }
        return dp[n - 1];
    }
};