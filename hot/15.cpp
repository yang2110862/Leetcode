#include "header.h"

//三数之和

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int sum = nums[i];
            int target = -sum;
            int l = i + 1, r = n - 1;
            while (l < r) {
                int s = nums[l] + nums[r];
                if (s == target) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    --r;
                    while (l < n && nums[l] == nums[l - 1]) ++l;
                    while (r >= 0 && nums[r] == nums[r + 1]) --r;
                } else if (s < target) {
                    ++l;
                } else {
                    --r;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<int> nums{0,0,0,0};
    auto x = test.threeSum(nums);
}