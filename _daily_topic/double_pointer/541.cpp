#include "header.h"
#include <cmath>
#include <algorithm>
//反转字符串 II
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        int p1 = min(0, n - 1);
        int p2 = min(k - 1, n - 1);
        while (p1 != p2) {
            int temp1 = p1, temp2 = p2;
            while (temp1 < temp2) {
                swap(s[temp1++], s[temp2--]);
            }
            p1 = min(p1 + 2 * k, n - 1);
            p2 = min(p2 + 2 * k, n - 1);
        }
        return s;
    }
};