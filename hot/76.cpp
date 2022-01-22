#include "header.h"

// 最小覆盖子串

//减少时间复杂度
class Solution {
private:
    unordered_map<char, int> cnt;
    unordered_map<char, int> windowCnt;
    bool isMatch(const string& s, const string& t) {
        for (auto it : cnt) {
            char c = it.first;
            int num = it.second;
            if (!windowCnt.count(c)) return false;
            if (windowCnt[c] < num) return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        for (auto c : t) {
            cnt[c]++;
        }
        int index = 0;
        int len = INT_MAX;
        int n = s.size();
        int l = 0, r = 0;
        while (r < n) {
            string new_s = s.substr(l, r - l + 1);
            windowCnt[s[r]]++;
            while (isMatch(new_s, t)) {
                if (new_s.size() < len) {
                    index = l;
                    len = new_s.size();
                }
                windowCnt[s[l]]--;
                ++l;
                new_s = s.substr(l, r - l + 1);
            }
            ++r;
        }
        if (len == INT_MAX) return "";
        return s.substr(index, len);
    }
};
