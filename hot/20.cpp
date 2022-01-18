#include "header.h"

// 有效的括号

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else if (c == ')') {
                if (stk.size() == 0 || stk.top() != '(') return false;
                stk.pop();
            } else if (c == ']') {
                if (stk.size() == 0 || stk.top() != '[') return false;
                stk.pop();
            } else {
                if (stk.size() == 0 || stk.top() != '{') return false;
                stk.pop();
            }
        }
        return stk.size() == 0;
    }
};