#include "header.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];
            int L = i + 1, R = n - 1;
            while (L < R) {
                if (nums[L] + nums[R] == target) {
                    ans.push_back(vector<int>{nums[i], nums[L], nums[R]});
                    while (L < R && nums[L] == nums[L + 1]) ++L;
                    while (L < R && nums[R - 1] == nums[R]) --R;
                    ++L;
                    --R;
                } else if (nums[L] + nums[R] < target) {
                    ++L;
                } else {
                    --R;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums{-1,0,1,2,-1,-4};
    Solution test;
    auto x = test.threeSum(nums);
    for (auto a : x) {
        for (auto c : a) {
            cout << c;
        }
        cout << endl;
    }
}