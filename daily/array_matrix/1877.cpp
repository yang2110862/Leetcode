#include "header.h"
//数组中最大数对和的最小值

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int sum;
        int res = 0;
        for (int i = 0; i < n / 2; ++i) {
            sum = nums[i] + nums[n - i - 1];
            res = max(res, sum);
        }
        return res;
    }
};