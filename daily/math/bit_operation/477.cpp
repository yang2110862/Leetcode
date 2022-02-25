#include "header.h"

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < 30; ++i) {
            int c = 0;
            for (auto& num : nums) {
                if (num & 1) {
                    ++c;
                }
                num >>= 1;
            }
            ans += c * (n - c);
        }
        return ans;
    }
};