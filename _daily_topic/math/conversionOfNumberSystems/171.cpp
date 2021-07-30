#include "header.h"

class Solution {
public:
    int titleToNumber(string columnTitle) {
        long coe = 1;
        reverse(columnTitle.begin(), columnTitle.end());
        long ans = 0;
        for (auto c : columnTitle) {
            ans += coe * (c - 'A' + 1);
            coe *= 26;
        }
        return ans;
    }
};