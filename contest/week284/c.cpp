#include "header.h"

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1 && k & 1) {
            return -1;
        }
        int maxn = nums[0];
        for (int i = 0; i < k - 1 && i < n; ++i) {
            maxn = max(maxn, nums[i]);
        }
        if (k < n) {
            maxn = max(maxn, nums[k]);
        }
        return maxn;
    }
};