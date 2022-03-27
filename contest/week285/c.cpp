#include "header.h"

class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int k = (intLength + 1) / 2;
        long base = pow(10, k - 1);
        vector<long long> ans;
        for (auto query : queries) {
            if (query > 9 * base) {
                ans.push_back(-1);
            } else {
                long res = base + query + 1;
                string s = to_string(res);
                s.resize(intLength - k);
                reverse(s.begin(), s.end());
                for (auto c : s) {
                    res = res * 10 + c - '0';
                }
                ans.push_back(res);
            }
        }
        return ans;
    }
};