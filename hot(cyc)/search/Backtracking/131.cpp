#include "header.h"

class Solution {
private:
    bool isPalindrome(string& s) {
        int num = s.size();
        for (size_t i = 0; i < num / 2; ++i) {
            if (s[i] != s[num - i - 1]) {
                return false;
            }
        }
        return true;
    }
    void backtrace(string& s, vector<vector<string>>& ans, vector<string>& curStr, string& temp, int curNum) {
        for (size_t i = curNum; i < s.size(); ++i) {
            bool flag = 0;
            temp += s[i];
            if(isPalindrome(temp)) {
                curStr.push_back(temp);
                flag = 1;
                temp.clear();
            } else {
                break;
            }
            if (i == s.size() - 1) {
                ans.push_back(curStr);
            }
            if (flag) {
                backtrace(s, ans, curStr, temp, curNum + 1);
            }
            if (!flag) {
                temp = temp.substr(0, temp.size() - 1);
            }
        }
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curStr;
        string temp;
        backtrace(s, ans, curStr, temp, 0);
        return ans;
    }
};