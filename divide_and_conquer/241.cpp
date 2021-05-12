#include "header.h"

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int n = input.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            char x = input[i];
            if (x == '+' || x == '-' || x == '*') {
                auto left = diffWaysToCompute(input.substr(0, i));
                auto right = diffWaysToCompute(input.substr(i + 1));
                for (auto j : left) {
                    for (auto k : right) {
                        switch (x) { //switch比else if时间上效率更高，是用空间换时间
                            case '+':
                                ans.push_back(j + k);
                                break;
                            case '-':
                                ans.push_back(j - k);
                                break;
                            case '*':
                                ans.push_back(j * k);
                                break;
                        }
                    }
                }
            }
        }
        if (ans.empty()) {
            ans.push_back(stoi(input));
        }
        return ans;
    }
};