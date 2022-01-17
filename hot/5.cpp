#include "header.h"

// 最长回文子串

//wrong
class Solution1 {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ans = 1;
        int index = 0;
        for (int mid = 0; mid <= n / 2; ++mid) {
            int left = mid - 1, right = mid + 1;
            int len = 1;
            while (left >= 0 && right < n) {
                if (s[left] == s[right]) {
                    len += 2;
                    left--;
                    right++;
                } else {
                    if (len > ans) {
                        ans = len;
                        index = left + 1;
                    } 
                    break;
                }
            }
            left = mid - 1, right = mid + 1;
            len = 1;

        }
        return s.substr(index, ans);
    }
};

//dp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        int maxLen = 1;
        int beg = 0;
        for (int L = 2; L <= n; ++L) {
            int len = 0;
            for (int i = 0; i < n; ++i) {
                int j = i + L - 1;
                if (j == n) break;
                if (L == 2) {
                    if (s[i] == s[j]) {
                        dp[i][j] = true;
                    }
                } else {
                    if (s[i] == s[j]) {
                        if (dp[i + 1][j - 1]) {
                            dp[i][j] = true;
                        }
                    }
                }
                if (dp[i][j]) {
                    if (L > maxLen) {
                        maxLen = L;
                        beg = i;
                    }
                }
            }
        }
        return s.substr(beg, maxLen);
    }
};