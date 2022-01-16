#include "header.h"

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int last[26];
        int n = S.size();
        for (int i = 0; i < n; ++i) {
            last[S[i] - 'a'] = i;
        }
        int end = 0, beg = 0;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            end = max(end, last[S[i] - 'a']);
            if (end == i) {
                ans.push_back(end - beg + 1);
                beg = end + 1;
            }
        }
        return ans;
    }
};