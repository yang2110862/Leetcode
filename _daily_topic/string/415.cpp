#include "header.h"

//字符串相加

class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        int p1 = m - 1, p2 = n - 1;
        string ans;
        int carry = 0;
        while (p1 >=0 || p2 >= 0 || carry) {
            int x = p1 >= 0 ? num1[p1] - '0' : 0;
            int y = p2 >= 0 ? num2[p2] - '0' : 0;
            int sum = x + y + carry;
            ans += ('0' + sum % 10);
            carry = sum / 10;
            --p1;
            --p2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};