#include "header.h"

//下一个排列
//可优化
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        bool flag = false;
        for (int i = n - 1; i >= 1; --i) {
            if (nums[i] <= nums[i - 1]) {
                continue;
            } else {
                int index = i - 1;
                int num = nums[index];
                int temp = INT_MAX;
                for (int j = n - 1; j >= i; --j) {
                    if (nums[j] > num && nums[j] < temp) {
                        index = j;
                        temp = nums[j];
                    }
                }
                swap(nums[i - 1], nums[index]);
                sort(nums.begin() + i, nums.end());
                flag = true;
                break;
            }
        }
        if (!flag) {
            reverse(nums.begin(), nums.end());
        }
    }
};