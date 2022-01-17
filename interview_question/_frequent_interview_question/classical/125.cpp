#include "header.h"

class Solution1 {
private:
    string getNew(string s) {
        string ans;
        for (char c : s) {
            if (c >= 'a' && c <= 'z') ans += c;
            else if (c >= 'A' && c <= 'Z') ans += 'a' + c - 'A';
            else if (c >= '0' && c <= '9') ans += c;
        }
        return ans;
    }
public:
    bool isPalindrome(string s) {
        string s_new = getNew(s);
        int n = s_new.size();
        int l = 0, r = n - 1;
        while (l < r) {
            if (s_new[l++] != s_new[r--]) return false;
        }
        return true;
    }
};

//  考察字符串API   tolower(ch)  isalnum(ch)        string b(s.rbegin(), s.rend())  
class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;
        for (char ch: s) {
            if (isalnum(ch)) {
                sgood += tolower(ch);
            }
        }
        string sgood_rev(sgood.rbegin(), sgood.rend());
        return sgood == sgood_rev;
    }
};
