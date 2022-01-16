#include "header.h"


//分情况累加dp
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (s[0] == '0') return 0;
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            if (can_combine(s[i - 2], s[i - 1])) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
private:
    bool can_combine(char a, char b) {
        if (a == '1')  return true;
        else if (a == '2' && b < '7') return true;
        else return false;
    }
};