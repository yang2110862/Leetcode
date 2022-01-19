#include "header.h"

// 最长有效括号
// dp
class Solution1 {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == '(') {
                dp[i] = 0;
            } else {
                if (i - 2 >= 0 && s[i - 2] == '(') {
                    dp[i] = dp[i - 2] + 2;
                } else if (i - 2 >= 0 && s[i - 2] == ')' && i - dp[i - 1] - 2 >= 0 && s[i - dp[i - 1] - 2] == '(') {
                    dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

//stack

class Solution {
public:
    int longestValidParentheses(string s) {

    }
};