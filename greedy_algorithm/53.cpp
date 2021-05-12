#include "header.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxn = nums[0];
        int temp = 0;
        for (int i = 0; i < n; ++i) {
            temp = max(nums[i], nums[i] + temp);
            maxn = max(temp, maxn);
        }
        return maxn;
    }
};