#include "header.h"
class Solution {
private:
    bool isSubstr(string s, string target) {
        int count = 0;
        int p1 = 0, p2 = 0;
        while (p1 < s.size() && p2 < target.size()) {
            if (s[p1] == target[p2]) {
                count++;
                p1++;
                p2++;
            } else {
                p1++;
            }
        }
        return count == target.size();
    }
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        for (const auto &x : dictionary) {
            if (x.size() < ans.size() || (x.size() == ans.size() && x > ans)) {
                continue;
            } else {
                if (isSubstr(s, x)) {
                    ans = x;
                }
            }
        }
        return ans;
    }
};