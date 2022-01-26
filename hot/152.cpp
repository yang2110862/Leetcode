#include "header.h"

//乘积最大子数组

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpMax(n);
        vector<int> dpMin(n);
        dpMax[0] = dpMin[0] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; ++i) {
            dpMin[i] = min(min(dpMin[i - 1] * nums[i], dpMax[i - 1] * nums[i]), nums[i]);
            dpMax[i] = max(max(dpMin[i - 1] * nums[i], dpMax[i - 1] * nums[i]), nums[i]);
            ans = max(dpMax[i], ans);
        }
        return ans;
    }
};