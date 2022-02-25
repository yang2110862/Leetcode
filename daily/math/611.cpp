#include "header.h"
//有效三角形的个数
class Solution1 {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int upper = lower_bound(nums.begin(), nums.end(), nums[i] + nums[j]) - nums.begin();
                int num = upper - 1 - j;
                if (num > 0) {
                    ans += num;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int k = i + 1;
            for (int j = i + 1; j < n; ++j) {
                while (k < n && nums[k] < nums[i] + nums[j]) {
                    ++k;
                }
                ans += max((k - 1 - j), 0);
            }
        }
        return ans;
    }
};