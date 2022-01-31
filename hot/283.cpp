#include "header.h"

//移动零

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int p = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) swap(nums[i], nums[p++]);
        }
    }
};

int main() {
    Solution test;
    vector<int> nums{0, 1, 0, 3, 12};
    test.moveZeroes(nums);
}