#include "header.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n - 2;
        while (low <= high) {
            int m = low + (high - low) / 2;
            if (nums[m] < nums[m - 1] && nums[m] < nums[m + 1]) {
                return nums[m];
            } else if (nums[m] > nums[0]) {
                low = m + 1;
            } else {
                high = m - 1;
            }
        }
        return min(nums[0], nums[n - 1]);
    }
};