#include "header.h"
//最长回文子串
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        int maxLen = 1;
        int begIndex = 0;
        for (int L = 2; L <= n; ++L) {
            for (int i = 0; i < n; ++i) {
                int j = i + L - 1;
                if (j >= n) break;
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j == i + 1) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                    if (dp[i][j] && L > maxLen) {
                            maxLen = L;
                            begIndex = i;
                    }
                }
            }
        }
        return s.substr(begIndex, maxLen);
    }
};