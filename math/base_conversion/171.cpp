#include "header.h"

class Solution {
public:
    int titleToNumber(string columnTitle) {
        long ans = 0;
        long coe = 1;
        string ver_s(columnTitle.rbegin(), columnTitle.rend());
        for (auto c : ver_s) {
            ans += coe * (c - 'A' + 1);
            coe *= 26;
        }
        return ans;
    }
};