#include "header.h"

//dp

class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int m = floor.size();
        vector<vector<int>> dp(m + 1, vector<int>(numCarpets + 1));
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = dp[i - 1][0] + floor[i - 1] - '0';
        }        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= numCarpets; ++j) {
                dp[i][j] = min(dp[i - 1][j] + floor[i - 1] - '0', dp[max(i - carpetLen,0)][j - 1]);
            }
        }
        return dp[m][numCarpets];
    }
};

int main() {
    Solution test;
    string floor = "1011";
    cout << test.minimumWhiteTiles(floor, 1, 2);
}