#include "header.h"
// 238.除自身以外数组的乘积
// O(n^2)空间复杂度
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> L(n, 1), R(n, 1);
        for (int i = 1; i < n; ++i) {
            L[i] = L[i - 1] * nums[i - 1];
        }
        for (int j = n - 2; j >= 0; --j) {
            R[j] = R[j + 1] * nums[j + 1];
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = L[i] * R[i];
        }
        return ans;
    }
};