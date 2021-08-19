#include "header.h"

//学生出勤记录 II

class Solution1 {
private:
    static constexpr int mod = 1000000000 + 7;
    int backtrack(int day, int A, int continuous_L, int n, vector<vector<vector<int>>>& visited) {
        if (day == n + 1) return 1;
        if (visited[day][A][continuous_L] != 0) return visited[day][A][continuous_L];
        int ans = 0;
        ans = (ans + backtrack(day + 1, A, 0, n, visited)) % mod;
        if (A < 1) {
            ans = (ans + backtrack(day + 1, A + 1, 0, n, visited)) % mod;
        }
        if (continuous_L < 2) {
            ans = (ans + backtrack(day + 1, A, continuous_L + 1, n, visited)) % mod;
        }
        visited[day][A][continuous_L] = ans;
        return ans;
    }
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> visited(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        int ans = backtrack(1, 0, 0, n, visited);
        return ans;
    }
};

//dp
class Solution {
private:
    static constexpr int mod = 1000000000 + 7;
public:
    int checkRecord(int n) {
        vector<vector<long>> dp(2, vector<long>(3, 0));
        dp[0][0] = 1;
        dp[1][0] = 1;
        dp[0][1] = 1;
        int temp00, temp01, temp02, temp10, temp11, temp12;
        for (int i = 1; i < n; ++i) {
            temp00 = (dp[0][0] + dp[0][1] + dp[0][2]) % mod;
            temp01 = dp[0][0];
            temp02 = dp[0][1];
            temp10 = (dp[0][0] + dp[0][1] + dp[0][2] + dp[1][0] + dp[1][1] + dp[1][2]) % mod;
            temp11 = dp[1][0];
            temp12 = dp[1][1];
            dp[0][0] = temp00;
            dp[0][1] = temp01;
            dp[0][2] = temp02;
            dp[1][0] = temp10;
            dp[1][1] = temp11;
            dp[1][2] = temp12;
        }
        int sum = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                sum = (sum + dp[i][j]) % mod;
            }
        }
        return sum;
    }
};
