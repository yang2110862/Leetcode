#include "header.h"


//当l = r - 1时，特殊考虑
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (nums[m] == target) return m;
            if (nums[l] > target) {
                if (nums[m] > nums[l]) {
                    l = m + 1;
                } else if (nums[m] < nums[l]){
                    if (nums[m] > target) {
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                } else {
                    l = l + 1;
                }
            } else {
                if (nums[m] > nums[l]) {
                    if (nums[m] > target) {
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                } else if (nums[m] < nums[l]){
                    r = m - 1;
                } else {
                    l = l + 1;
                }
            }
        }
        return -1;
    }
};