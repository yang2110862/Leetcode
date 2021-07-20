#include "header.h"
//最高频元素的频数
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); 
        int left = 0, right = 1;
        int n = nums.size();
        long total = 0;
        int res = 1;
        while (right < n) {
            total += (long)(nums[right] - nums[right - 1]) * (right - left);
            while (total > k) {
                total -= (nums[right] - nums[left]);
                ++left;
            }
            res = max(res, right - left + 1);
            ++right;
        }
        return res;
    }
};