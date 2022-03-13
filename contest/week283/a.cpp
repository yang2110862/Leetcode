#include "header.h"

class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        char begC = s[0], endC = s[3];
        char begR = s[1], endR = s[4];
        for (char c = begC; c <= endC; ++c) {
            for (char r = begR; r <= endR; ++r) {
                string temp;
                temp += c;
                temp += r;
                ans.push_back(temp);
            }
        }
        return ans;
    }
};

int main() {
    Solution test;
    string s = "K1:L1";
    auto x = test.cellsInRange(s);
}