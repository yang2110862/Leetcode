#include "header.h"

//回文子串

class Solution {
private:
    bool check(string s) {
        string temp = s;
        reverse(s.begin(), s.end());
        if (temp == s) return true;
        else return false;
    }
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= (n - i); ++j) {
                string temp = s.substr(i, j);
                if (check(temp)) ++ans;
            }
        }
        return ans;
    }
};