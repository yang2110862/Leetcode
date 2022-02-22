#include "header.h"

//找到字符串中所有字母异位词

class Solution {
private:
    bool check(string& s1, string& s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int n = s1.size();
        for (int i = 0; i < n; ++i) {
            if (s1[i] == s2[i]) continue;
            else return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<int> ans;
        for (int i = 0; i < m; ++i) {
            if (i + n <= m) {
                string c = s.substr(i, n);
                if (check(c, p)) {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};

//滑动窗口

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        vector<int> sCount(26);
        vector<int> pCount(26);
        if (m < n) return {};
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            sCount[s[i] - 'a']++;
            pCount[p[i] - 'a']++;
        }
        if (sCount == pCount) ans.push_back(0);
        for (int i = 0; i < m - n; ++i) {
            sCount[s[i] - 'a']--;
            sCount[s[i + n] - 'a']++;
            if (sCount == pCount) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};