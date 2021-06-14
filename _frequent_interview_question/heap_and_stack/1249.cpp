#include "header.h"

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') stk.push(i);
            else if (s[i] == ')') {
                if (stk.empty()) s[i] == ' ';
                else stk.pop();
            }
        }
        while (!stk.empty()) {
            s[stk.top()] = ' ';
            stk.pop();
        }
        string ans;
        for (int i = 0; i < n; ++i) {
            if (s[i] != ' ') ans += s[i];
        }
        return ans;
    }
};