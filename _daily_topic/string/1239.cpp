#include "header.h"

//__builtin_popcount(x)  计算x二进制中含1的个数
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> masks;
        for (auto& str : arr) {
            int mask = 0;
            for (char c : str) {
                c -=  'a';
                if ((mask >> c) & 1) {
                    mask = 0;
                    break;
                }
                mask |= 1 << c;
            }
            if (mask) {
                masks.push_back(mask);
            }    
        }
        int ans = 0;
        function<void(int, int)> backtrack = [&](int pos, int mask) {
            if (pos == masks.size()) {
                ans = max(ans, __builtin_popcount(mask));
                return;
            }
            if ((masks[pos] & mask) == 0) {
                backtrack(pos + 1, mask | masks[pos]);
            }
            backtrack(pos + 1, mask);
        };
        backtrack(0, 0);
        return ans;
    }
};