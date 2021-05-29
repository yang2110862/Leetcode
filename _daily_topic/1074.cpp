#include "header.h"

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        for (int x1 = 1; x1 <= m; ++x1) {
            for (int y1 = 1; y1 <= n; ++y1) {
                vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
                for (int x2 = x1; x2 <= m; ++x2) {
                    for (int y2 = y1; y2 <= n; ++y2) {
                        dp[x2][y2] = dp[x2 - 1][y2] + dp[x2][y2 - 1] - dp[x2 - 1][y2 - 1] + matrix[x2 - 1][y2 - 1];
                        if (dp[x2][y2] == target) ++ans;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<vector<int>> matrix{{0,1,0}, {1,1,1}, {0,1,0}};
    int target = 0;
    cout << test.numSubmatrixSumTarget(matrix, target);
    return 0;
}