#include "header.h"

class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sums.resize(n + 1);
        sums[0] = 0;
        for (int i = 1; i <= n; ++i) sums[i] = sums[i - 1] + nums[i - 1];
    }
    
    int sumRange(int left, int right) {
        return sums[right + 1] - sums[left];
    }
private:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */