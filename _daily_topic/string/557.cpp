#include "header.h"

class Solution {
private:
    string reverseWord(string s) {
        int n = s.size();
        int p1 = 0, p2 = n - 1;
        while (p1 < p2) {
            swap(s[p1++], s[p2--]);
        }
        return s;
    }
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string> words;
        string temp;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c == ' ') {
                words.push_back(temp);
                temp.clear();
            } else {
                temp += c;
            }
        }
        if (!temp.empty()) words.push_back(temp);
        n = words.size();
        string ans;
        for (int i = 0; i < n; ++i) {
            ans += reverseWord(words[i]);
            if (i != n - 1) ans += ' ';
        }
        return ans;
    }
};