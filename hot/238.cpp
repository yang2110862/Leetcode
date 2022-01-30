#include "header.h"

//除自身以外数组的乘积

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = right[n - 1] = 1;
        for (int i = 1; i < n; ++i) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; --i) {
            right[i] = right[i + 1] * nums[i + 1];
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int sum = left[i] * right[i];
            ans.push_back(sum);
        }
        return ans;
    }
};