#include "header.h"

//比特位计数

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        ans[0] = 0;
        int index = 1;
        int bit = 1;
        while (index <= n) {
            ans[index++] = 1;
            for (int i = 1; i < bit; ++i) {
                if (index > n) break;
                ans[index++] = ans[i] + 1;
            }
            bit <<= 1;
        }
        return ans;
    }
};