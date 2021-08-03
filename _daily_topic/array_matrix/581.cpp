#include "header.h"
#include <climits>
//最短无序连续子数组
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int min_num = INT_MAX;
        int left = n - 1;
        for (int i = n - 1; i >= 1; --i) {
            min_num = min(min_num, nums[i]);
            if (min_num < nums[i - 1]) {
                left = i - 1;
            }
        }
        int right = 0;
        int max_num = INT_MIN;
        for (int i = 0; i < n - 1; ++i) {
            max_num = max(max_num, nums[i]);
            if (max_num > nums[i + 1]) {
                right = i + 1;
            }
        }
        return right - left + 1;
    }
};