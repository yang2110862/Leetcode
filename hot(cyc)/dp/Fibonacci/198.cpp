#include "header.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return nums[0];
        else if (len == 2) return max(nums[0], nums[1]);
        else return max(rob(nums, 0, len - 2), rob(nums, 1, len - 1));
    }
private:
    int rob(vector<int>& nums, int beg, int end) {
        int first = nums[beg], second = max(nums[beg], nums[beg + 1]);
        for (int i = beg + 2; i <= end; ++i) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }
};