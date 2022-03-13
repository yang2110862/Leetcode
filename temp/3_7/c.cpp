#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    long long GetSubArrayMaxProduct(vector<long>& nums) {
        int n = nums.size();
        vector<long> dpMin(n + 1);
        vector<long> dpMax(n + 1);
        dpMax[0] = dpMin[0] = 1;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            dpMax[i] = max(nums[i - 1], max(nums[i - 1] * dpMin[i - 1], nums[i - 1] * dpMax[i - 1]));
            dpMin[i] = min(nums[i - 1], min(nums[i - 1] * dpMin[i - 1], nums[i - 1] * dpMax[i - 1]));
            ans = max((int)dpMax[i], ans);
        }
        return ans;
    }
};
