#include "header.h"

//分割等和子集

//TL  NP问题暴力法超时
class Solution1 {
private:
    bool backtrace(int target, int num, int index, const vector<int>& nums){
        if (num == target) {
            return true;
        }
        if (index == nums.size() || num > target) return false;
        if (backtrace(target, num, index + 1, nums) || backtrace(target, num + nums[index], index + 1, nums)) {
            return true;
        }
        return false;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(), nums.end(), less<int>());
        for (auto num : nums) {
            sum += num;
        }
        if (sum & 1) return false;
        int target = sum / 2;
        return backtrace(target, 0, 0, nums);
    }
};


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }
        if (sum & 1) return false;
        int target = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <=target; ++j) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            if (dp[i][target] == true) return true;
        }
        return false;
    }
};

int main() {
    vector<int> nums{100};
    Solution test;
    cout << test.canPartition(nums);
}
