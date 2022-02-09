#include "header.h"

//字符串解码

class Solution {
private:
    string getNum(const string& s, int& p) {
        string res = "";
        while (isdigit(s[p])) {
            res += s[p++];
        }
        return res;
    }
    string getStr(const vector<string>& arr) {
        string res = "";
        for (auto s : arr) {
            res += s;
        }
        return res;
    }
public:
    string decodeString(string s) {
        vector<string> stk;
        int n = s.size();
        int p = 0;
        while (p < n) {
            char c = s[p];
            if (isdigit(c)) {
                string num = getNum(s, p);
                stk.push_back(num);
            } else if (isalpha(c) || c == '[') {
                ++p;
                stk.push_back(string(1, c));
            } else {
                ++p;
                vector<string> temp;
                while (stk.back() != "[") {
                    temp.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(temp.begin(), temp.end());
                stk.pop_back();
                int time = stoi(stk.back());
                stk.pop_back();
                string newS;
                string combine = getStr(temp);
                for (int i = 0; i < time; ++i) {
                    newS += combine;
                }
                stk.push_back(newS);
            }
        }
        return getStr(stk);
    }
};