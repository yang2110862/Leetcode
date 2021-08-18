#include "header.h"

//学生出勤记录 II

class Solution {
private:
    static constexpr int mod = 1000000000 + 7;
    int backtrack(int day, int A, int continuous_L, int n, vector<vector<vector<int>>>& visited) {
        if (day == n + 1) return 1;
        if (visited[day][A][continuous_L] != 0) return visited[day][A][continuous_L];
        int ans = 0;
        ans = (ans + backtrack(day + 1, A, 0, n, visited)) % mod;
        if (A < 1) {
            ans = (ans + backtrack(day + 1, A + 1, continuous_L, n, visited)) % mod;
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