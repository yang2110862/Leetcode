#include "header.h"

//删除无效的括号

class Solution {
private:
    vector<string> ans;
    void backtrace(string s, int index, int lremove, int rremove) {
        if (lremove == 0 && rremove == 0) {
            if (isValid(s)) {
                ans.push_back(s);
            }
            return;
        }
        for (int i = index; i < s.size(); ++i) {
            if (i != index && s[i] == s[i - 1]) continue;
            if (s.size() - i < lremove + rremove) break;
            if (s[i] == '(' && lremove > 0) {
                backtrace(s.substr(0, i) + s.substr(i + 1), i, lremove - 1, rremove);
            }
            if (s[i] == ')' && rremove > 0) {
                backtrace(s.substr(0, i) + s.substr(i + 1), i, lremove, rremove - 1);
            }
        }
    }
    bool isValid(string s) {
        int cnt = 0;
        for (auto c : s) {
            if (c == '(') {
                ++cnt;
            } else if (c == ')') {
                --cnt;
                if (cnt < 0) return false;
            }
        }
        return cnt == 0;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int lremove = 0, rremove = 0;
        int cnt = 0;
        for (auto c : s) {
            if (c == '(') {
                ++cnt;
            } else if (c == ')') {
                if (cnt == 0) ++rremove;
                else --cnt;
            }
        }
        lremove = cnt;
        backtrace(s, 0, lremove, rremove);
        return ans;
    }
};