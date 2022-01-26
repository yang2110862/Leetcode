#include "header.h"

//打家劫舍

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpsteal(n);
        vector<int> dpNosteal(n);
        dpsteal[0] = nums[0];
        dpNosteal[0] = 0;
        for (int i = 1; i < n; ++i) {
            dpsteal[i] = max(nums[i], dpNosteal[i - 1] + nums[i]);
            dpNosteal[i] = max(dpsteal[i - 1], dpNosteal[i - 1]);
        }
        return max(dpsteal[n - 1], dpNosteal[n - 1]);
    }
};