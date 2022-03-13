#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// #define long long LL

class Solution1 {
public:
    long long GetMinCalculateCount(long long sourceX, long long sourceY, long long targetX, long long targetY) {
        if (sourceY == targetY && sourceX == targetX) return 0;
        vector<vector<long long>> dp(targetX + 1, vector<long long>(targetY + 1, -1));
        dp[sourceX][sourceY] = 0;
        for (long long i = sourceX; i <= targetX; ++i) {
            for (long long j = sourceY; j <= targetY; ++j) {
                int num1 = -1;
                if (dp[i - 1][j - 1] != - 1) {
                    num1 = dp[i - 1][j - 1] + 1;
                }
                int num2 = -1;
                if (i % 2 == 0 && j % 2 == 0) {
                    if (dp[i / 2][j / 2] != -1) {
                        num2 = dp[i / 2][j / 2] + 1;
                    }
                }
                if (num1 != -1 && num2 != -1) {
                    dp[i][j] = min(num1, num2);
                } else if (num1 != -1) {
                    dp[i][j] = num1;
                } else if (num2 != -1) {
                    dp[i][j] = num2;
                }
            }
        }
        return dp[targetX][targetY];
    }
};

class Solution2 {
public:
    long long GetMinCalculateCount(long long sourceX, long long sourceY, long long targetX, long long targetY) {
        if (sourceY == targetY && sourceX == targetX) return 0;
        if (sourceY < targetY || sourceX < targetX) return -1;
        queue<pair<long long, long long>> q;
        q.push(make_pair(sourceX, sourceY));
        // vector<vector<bool>> visited(targetX + 1, vector<bool>(targetY + 1, false));
        long long ans = 0;
        while (!q.empty()) {
            long long n = q.size();
            ++ans;
            for (long long i = 0; i < n; ++ i) {
                auto temp = q.front();
                q.pop();
                if (temp.first + 1 <= targetX && temp.second + 1 <= targetY
                ) {
                    q.push(make_pair(temp.first + 1, temp.second + 1));
                    if (temp.first + 1 == targetX && temp.second + 1 == targetY) {
                        return ans;
                    }
                }
                if (temp.first * 2 <= targetX && temp.second * 2 <= targetY
                ) {
                    q.push(make_pair(temp.first * 2, temp.second * 2));
                    if (temp.first * 2 == targetX && temp.second * 2 == targetY) {
                        return ans;
                    }
                }
            }
        }
        return -1;
    }
};

class Solution {
private:
    bool dfs(long long sourceX, long long sourceY, long long targetX, long long targetY, int cnt) {
        if (sourceX == targetX && sourceY == targetY) {
            return true;
        }
    }
public:
    long long GetMinCalculateCount(long long sourceX, long long sourceY, long long targetX, long long targetY) {
        // write code here
    }
};

int main() {
    Solution test;
    cout << test.GetMinCalculateCount(1, 1, 4, 4);
}