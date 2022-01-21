#include "header.h"

//最小路径和

//回溯法TL
class Solution1 {
private:
    int ans = INT_MAX;
    void backtrace(const vector<vector<int>>& grid, int i, int j, int m, int n, int sum) {
        if (i > m - 1 || j > n - 1) return;
        sum += grid[i][j];
        if (sum > ans) return;
        if (i == m - 1 && j == n - 1) {
            ans = min(sum, ans);
        }
        vector<vector<int>> dirs{{0, 1}, {1, 0}};
        for (auto& dir : dirs) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            backtrace(grid, new_i, new_j, m, n, sum);
        }
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        backtrace(grid, 0, 0, m, n, 0);
        return ans;
    }
};

//dp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i - 1 < 0 && j - 1 < 0) continue;
                if (i - 1 < 0) {
                    dp[i][j] = dp[i][j - 1] + grid[i][j - 1];
                } else if (j - 1 < 0) {
                    dp[i][j] = dp[i - 1][j] + grid[i - 1][j];
                } else {
                    dp[i][j] = min(dp[i][j - 1] + grid[i][j - 1], dp[i - 1][j] + grid[i - 1][j]);
                }
            }
        }
        return dp[m - 1][n - 1] + grid[m - 1][n - 1];
    }
};