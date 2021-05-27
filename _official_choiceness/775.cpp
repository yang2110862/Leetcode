#include "header.h"

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        int max_value = INT_MIN;
        for (int i = 2; i < n; ++i) {
            max_value = max(max_value, nums[i - 2]);
            if (nums[i] < max_value) return false;
        }
        return true;
    }
};

int main() {
    Solution test;
    vector<int> nums{0,2,3,1};
    cout << test.isIdealPermutation(nums);
    return 0;
}