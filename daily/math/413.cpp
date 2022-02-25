#include "header.h"

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n);
        for (int i = 1; i < n; ++i) {
            diff[i] = nums[i] - nums[i - 1];
        }
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            int offset = nums[i] - nums[i - 1];
            for (int j = i - 1; j >= 1; --j) {
                if (diff[j] == offset) ++ ans;
                else break;
            }
        }
        return ans;
    }
};

//o(1)空间复杂度

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        if (n <= 2) return ans;
        int diff = nums[1] - nums[0];
        int num = 1;
        for (int i = 2; i < n; ++i) {
            int offset = nums[i] - nums[i - 1];
            if (offset == diff) {
                ans += num;
                ++num;
            } else {
                num = 1;
                diff = offset;
            }
        }
        return ans;
    }
};