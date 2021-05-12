#include "header.h"

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i < n && ans < 2; ++i) {
            if (nums[i] >= nums[i - 1]) {
                continue;
            }
            ++ans;
            if (i >= 2 && nums[i] < nums[i - 2]) {
                nums[i] = nums[i - 1];
            } else {
                nums[i - 1] = nums[i];
            }
        }
        return ans < 2;
    }
};