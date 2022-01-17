#include "header.h"

class Solution {
private:
    unordered_map<char, string> phoneMap{
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    void backtrack(vector<string>& ans, string& digits, string& combination, int index) {
        if (index == digits.size()) ans.push_back(combination);
        else {
            for (auto x : phoneMap[digits[index]]) {
                combination.push_back(x);
                backtrack(ans, digits, combination, index + 1);
                combination.pop_back();
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        string combination;
        vector<string> ans;
        backtrack(ans, digits, combination, 0);
        return ans;
    }
};