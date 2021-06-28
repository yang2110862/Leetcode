#include "header.h"

class Solution {
public:
    string convertToTitle(int columnNumber) {
        int mod = 26;
        string ans;
        while (columnNumber) {
            ans += (--columnNumber % mod) + 'A';
            columnNumber = columnNumber / 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};