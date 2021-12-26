#include "header.h"
#include <sstream>
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        istringstream in(text);
        string temp;
        vector<string> ans;
        vector<string> stext;
        while(in >> temp) {
            stext.push_back(temp);
        }
        int n = stext.size();
        for (int i = 0; i < n - 2; ++i) {
            if (stext[i] == first && stext[i + 1] == second) {
                ans.push_back(stext[i + 2]);
            }
        }
        return ans;
    }
};