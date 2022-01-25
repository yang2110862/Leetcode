#include "header.h"

//单词拆分
//回溯 TL
class Solution1 {
private:
    bool backtrace(const string& s, const vector<string>& wordDict, int index) {
        if (index == s.size()) return true;
        for (auto word : wordDict) {
            int n = word.size();
            int p = index;
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                if (word[i] != s[p]) {
                    flag = false;
                    break;
                } else {
                    ++p;
                }
            }
            if (flag) {
                if (backtrace(s, wordDict, p)) return true;
            }
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return backtrace(s, wordDict, 0);
    }
};

//DP

class Solution {
private:
    unordered_set<string> st;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        for (const auto word : wordDict) {
            st.insert(word);
        }
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                if (dp[j - 1] && st.count(s.substr(j - 1, i - j + 1))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};