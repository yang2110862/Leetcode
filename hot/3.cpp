#include "header.h"

//无重复字符的最长子串


class Solution {
private:
    unordered_map<char, int> index;
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        int beg = 0;
        for (int i = 0; i < n; ++i) {
            int c = s[i];
            if (index.count(c)) {
                beg = max(index[c] + 1, beg);
                index[c] = i;
            } else {
                index[c] = i;
            }
            ans = max(ans, i - beg + 1);
        }
        return ans;
    }
};

int main() {
    Solution test;
    string s = "abba";
    cout << test.lengthOfLongestSubstring(s);
}