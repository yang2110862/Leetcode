#include "header.h"

class Solution {
private:
    void trackback(vector<string>& ans, string& combination, const unordered_map<char, string>& phoneMap, int index, string& digits){
        if(index == digits.size()) {
            ans.push_back(combination);
        } else {
            char digit = digits[index];
            const string& letters = phoneMap.at(digit);
            for (auto& x : letters) {
                combination.push_back(x);
                trackback(ans, combination, phoneMap, index + 1, digits);
                combination.pop_back();             //跟bfs不同的是，递归后要pop
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
        vector<string> ans;
        string combination;
        trackback(ans, combination, phoneMap, 0, digits);
        return ans;
    }
};