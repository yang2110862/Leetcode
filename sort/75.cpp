#include "header.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int num = nums.size();
        int low = -1, high = num;
        for (size_t i = 0; i < high; ++i) {
            while (nums[i] > 1 && i < high) {                    //切记用while不要用if，因为交换回来的数字可能还符合要求  并且防止数组越界
                swap(nums[--high], nums[i]);
            }
            if (nums[i] < 1 && i < high) {
                swap(nums[++low], nums[i]);
            }
        }
    }
};