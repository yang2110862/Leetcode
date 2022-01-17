#include "header.h"

class Solution {
private:
    unordered_map<char, int> s_mp, t_mp;
public:
    string minWindow(string s, string t) {
        int s_len = s.size();
        int t_len = t.size();
        for (auto c : t) {
            ++t_mp[c];
        }
        int distance = 0;
        int min_len = s_len + 1;
        int begin;
        int left = 0, right = 0;
        while (right < s.length()) {
            if (!t_mp.count(s[right])) {
                ++right;
                continue;
            }
            if (!s_mp.count(s[right]) || s_mp[s[right]] < t_mp[s[right]]) {
                ++distance;
            }
            ++s_mp[s[right]];
            while (distance == t_len) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    begin = left;
                }
                if (!t_mp.count(s[left])) {
                    ++left;
                    continue;
                }
                if (s_mp[s[left]] == t_mp[s[left]]) {
                    --distance;
                }
                --s_mp[s[left]];
                ++left;
            }
            ++right;
        }
        if (min_len == s_len + 1) return "";
        else return s.substr(begin, min_len);
    }
};

int main() {
    Solution test;
    string s = "AABC", t = "ABC";
    cout << test.minWindow(s, t);
}