#include "header.h"

// 括号生成


class Solution {
private:
    vector<string> ans;
    void backtrace(int left, int right, string combination) {
        if (!left && !right) {
            ans.push_back(combination);
            return;
        }
        if (left >= right) {
            combination += '(';
            backtrace(left - 1, right, combination);
        } else {
            if (left > 0) {
                combination += '(';
                backtrace(left - 1, right, combination);
                combination = combination.substr(0, combination.size() - 1);
            }
            if (right > 0) {
                combination += ')';
                backtrace(left, right - 1, combination);
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return ans;
        string combination;
        backtrace(n, n, combination);
        return ans;
    }
};

int main() {
    Solution test;
    int n = 1;
    auto x = test.generateParenthesis(n);
}