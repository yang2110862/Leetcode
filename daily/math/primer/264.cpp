#include "header.h"

//丑数 II


class Solution1 {
private:
    unordered_set<int> visited;
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> ugly_num;
        vector<long> ugly_arr{2, 3, 5};
        ugly_num.push(1);
        visited.insert(1);
        for (int i = 0; i < n - 1; ++i) {
            int cur = ugly_num.top();
            ugly_num.pop();
            for (auto num : ugly_arr) {
                if (!visited.count(cur * num)) {
                    ugly_num.push(cur * num);
                    visited.insert(cur * num);
                }
            }
        }
        return ugly_num.top();
    }
};

//dp

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long> dp(n);
        dp[0] = 1;
        int p1, p2, p3;
        p1 = 0, p2 = 0, p3 = 0;
        for (int i = 1; i < n; ++i) {
            int num1, num2, num3;
            num1 = dp[p1] * 2, num2 = dp[p2] * 3, num3 = dp[p3] * 5;
            dp[i] = min(min(num1, num2), num3);
            if (dp[i] == dp[p1] * 2) ++p1;
            if (dp[i] == dp[p2] * 3) ++p2;
            if (dp[i] == dp[p3] * 5) ++p3;
        }
        return dp[n - 1];
    }
};