#include "header.h"

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 1, right = n - 2;
        while (left <= right) {
            int m = left + (right - left) / 2;
            if (nums[m] != nums[m - 1] && nums[m] != nums[m + 1]) {
                return nums[m];
            }
            if (m % 2 == 0 && nums[m] == nums[m + 1]) {
                left = m + 1;
            } else if (m % 2 == 0 && nums[m] == nums[m - 1]) {
                right = m - 1;
            } else if (m % 2 == 1 && nums[m] == nums[m - 1]) {
                left = m + 1;
            } else {
                right = m - 1;
            }
        }
        if (right == 0) {
            return nums[0];
        } else {
            return nums[n - 1];
        }
    }
};