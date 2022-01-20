#include "header.h"

//在排序数组中查找元素的第一个和最后一个位置

class Solution {
private:
    int firstGreaterEqual(const vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r) >> 1;
            if (nums[m] >= target) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
    int lastGreaterEqual(const vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int m = ((l + r) >> 1) + 1;
            if (nums[m] <= target) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        return r;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        int index1 = firstGreaterEqual(nums, target);
        int index2 = lastGreaterEqual(nums, target);
        if (nums[index1] == target && nums[index2] == target) {
            return {index1, index2};
        } else {
            return {-1, -1};
        }
    }
};
