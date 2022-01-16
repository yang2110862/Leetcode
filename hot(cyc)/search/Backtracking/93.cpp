#include "header.h"

class Solution {
private:
    vector<string> ans;
    void backtrace(string& s,string& str, int cnt, int index) {
        if (cnt == 4 && index == s.size()) {
            ans.push_back(str.substr(0, str.size() - 1));  //去掉多余的一个.
        }
        if (cnt == 4 || index == s.size()) {
            return;
        }
        for (int i = 0; i < 3; ++i) {
            if (index + i > s.size() - 1) { //数组越界
                return;
            }
            if (s[index] == '0' && i !=0) {   //有前导0
                return;
            }
            if (i == 2 && s.substr(index, 3) > "255") {  //不合法
                return;
            }
            str += s.substr(index, i + 1);
            str.push_back('.');
            backtrace(s, str, cnt + 1, index + i + 1);
            str = str.substr(0, str.size() - 1 - (i + 1));
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        string str;
        backtrace(s, str, 0, 0);
        return ans;
    }
};