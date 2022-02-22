#include "header.h"

//最短无序连续子数组

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int p1 = 0, p2 = n - 1;
        while (p1 < n) {
            if (temp[p1] == nums[p1]) {
                ++p1;
            } else {
                break;
            }
        }
        while (p2 >= 0) {
            if (temp[p2] == nums[p2]) {
                --p2;
            } else {
                break;
            }
        }
        if (p1 == n) return 0;
        else return p2 - p1 + 1;
    }
};