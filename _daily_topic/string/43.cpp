#include "header.h"

class Solution {
private:
    string strAdd(string s1, string s2) {
        int m = s1.size() - 1, n = s2.size() - 1;
        string ans;
        int carry = 0;
        while (m >= 0 || n >= 0 || carry) {
            int x = m >= 0 ? (s1[m] - '0') : 0;
            int y = n >= 0 ? (s2[n] - '0') : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            ans += (sum % 10) + '0';
            --m;
            --n;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        string ans;
        int zero = 0;
        if (num1 == "0" || num2 == "0") return "0";
        for (int i = n - 1; i >= 0; --i) {
            int y = num2[i] - '0';
            string str1;
            int carry = 0;
            for (int j = m - 1; j >= 0; --j) {
                int x = num1[j] - '0';
                int ans = x * y + carry;
                carry = ans / 10;
                str1 += (ans % 10) + '0';
            }
            if (carry != 0) {
                str1 += carry + '0';
            }
            reverse(str1.begin(), str1.end());
            for (int i = 0; i < zero; ++i) {
                str1 += '0';
            }
            ++zero;
            ans = strAdd(ans, str1);
        }
        return ans;
    }
}; 

int main() {
    Solution test;
    string num1 = "123", num2 = "456";
    cout << test.multiply(num1, num2);

}