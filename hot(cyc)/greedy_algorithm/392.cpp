#include "header.h"
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        int p = 0;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            if (t[i] == s[p]) {
                ++p;
                ++ans;
            }
            if (ans == n) {
                break;
            }
        }
        return ans == n;
    }
};