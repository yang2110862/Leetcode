#include "header.h"

//数学推到后的节简版，不建议使用（或者是我还没理解透）
class Solution1 {
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

//进制的更重要的本质解法
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while (columnNumber > 0) {
            int a0 = (columnNumber - 1) % 26;
            ans += a0 + 'A';
            columnNumber = (columnNumber - a0) / 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};