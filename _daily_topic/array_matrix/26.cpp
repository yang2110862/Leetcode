#include "header.h"

//删除有序数组中的重复项
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write = 1;
        int n = nums.size();
        if (n == 0) return 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1]) continue;
            else nums[write++] = nums[i];
        }
        nums.resize(write);
        return write;
    }
};