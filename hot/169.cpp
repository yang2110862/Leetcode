#include "header.h"

//多数元素

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate = nums[0];
        int num = 1;
        for (int i = 1; i < n; ++i) {
            if (num == 0) {
                candidate = nums[i];
                num = 1;
            } else {
                if (nums[i] == candidate) ++num;
                else --num;
            }
        }
        return candidate;
    }
};