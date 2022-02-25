#include "header.h"


class Solution {
private:
    void backtracking(int left, int right, vector<string>& ans, string s) {
        if (!left && !right) {
            ans.push_back(s);
            return;
        }
        if (left < right) {
            if (left > 0) {
                backtracking(left - 1, right, ans, s + '(');
            }
            if (right > 0) {
                backtracking(left, right - 1, ans, s + ')');
            }
        } else {
            backtracking(left - 1, right, ans, s + '(');
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        backtracking(n, n, ans, s);
        return ans;
    }
};