#include "header.h"

// 最长公共前缀

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int minLen = 200;
        for (int i = 0; i < n; ++i) {
            minLen = min(minLen, (int)strs[i].size());
        }
        if (minLen == 0) return "";
        string ans;
        for (int i = 0; i < minLen; ++i) {
            char c = strs[0][i];
            bool flag = true;
            for (int j = 1; j < n; ++j) {
                if (strs[j][i] != c) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans += c;
            else break;
        }
        return ans;
    }
};