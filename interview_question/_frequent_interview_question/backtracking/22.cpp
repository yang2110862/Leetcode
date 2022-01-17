#include "header.h"

class Solution {
    void backtrack(int left, int right, vector<string>& ans, string combination) {
        if (!left && !right){ 
            ans.emplace_back(combination);
            return;
        }
        if (left < right) {
            //两个分支
            if (left > 0) {
                combination += '(';
                backtrack(left - 1, right, ans, combination);
                combination = combination.substr(0, combination.size() - 1);     //回溯
            }
            if (right > 0) {
                combination += ')';
                backtrack(left, right - 1, ans, combination);
            }
        } else {
            combination += '(';
            backtrack(left - 1, right, ans, combination);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string combination;
        backtrack(n, n, ans, combination);
        return ans;
    }
};

int main() {
    Solution test;
    auto x = test.generateParenthesis(2);
}