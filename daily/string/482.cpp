#include "header.h"
// 482. 密钥格式化
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string a;
        for (auto c : s) {
            if (c != '-') {
                if (islower(c)) {
                    a += toupper(c);
                } else {
                    a += c;
                }
            }
        }
        int len = a.size();
        string ans;
        int mod = len % k;
        int index = 0;
        if (mod != 0) {
            while (index < mod) {
                ans += a[index++];
            }
            if (index != len) ans += '-';
        }
        int l = 0;
        for (int i = index; i < len; ++i) {
            if (l == k) {
                ans += '-';
                l = 0;
            }
            ans += a[i];
            ++l;
        }
        return ans;
    }
};