#include "header.h"
//搜索旋转排序数组

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            int num = nums[m];
            if (num == target) return m;
            if (num >= nums[0]) {
                if (target > num) {
                    l = m + 1;
                } else {
                    if (target >= nums[0]) {
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                }
            } else {
                if (target < num) {
                    r = m - 1;
                } else {
                    if (target >= nums[0]) {
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                }
            }
        }
        return -1;
    }
};