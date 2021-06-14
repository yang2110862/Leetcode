#include "header.h"

class Solution {
private:
    unordered_map<char, char> mp{{'{', '}'}, 
    {'(', ')'}, {'[', ']'}
    };
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else if (c == ')' || c == '}' || c == ']') {
                if (stk.empty()) return false;
                if (mp[stk.top()] != c) return false;
                else stk.pop();
            } else return false;
        }
        if (!stk.empty()) return false;
        return true;
    }
};