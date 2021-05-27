#include "header.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (auto& word : wordDict) {
                int len = word.size();
                if (i - len >= 0 && s.substr(i - len, len) == word) {      //注意下标不要错
                    dp[i] = dp[i] || dp[i - len];
                }
            }
        }
        return dp[n];
    }
};