#include "header.h"

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (c == ')') {
                    if (st.empty() || st.top() != '(') return false;
                    else st.pop();
                } else if (c == '}') {
                    if (st.empty() || st.top() != '{') return false;
                    else st.pop();
                } else {
                    if (st.empty() || st.top() != '[') return false;
                    else st.pop();
                }
            }
        }
        if (st.empty()) return true;
        else return false;
    }
};

int main() {
    string s = "]";
    Solution test;
    cout << test.isValid(s);
}