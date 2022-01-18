#include "header.h"

//电话号码的字母组合

class Solution {
private:
    unordered_map<char, vector<char>> mp{
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };
    vector<string> ans;
    void backtrace(const string digits, int index, int n, string combination) {
        if (index == n) {
            ans.push_back(combination);
            return;
        }
        char c = digits[index];
        for (auto x : mp[c]) {
            combination += x;
            backtrace(digits, index + 1, n, combination);
            combination = combination.substr(0, combination.size() - 1);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string combination;
        int n = digits.size();
        if (n == 0) return ans;
        backtrace(digits, 0, n, combination);
        return ans;
    }
};