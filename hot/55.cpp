#include "header.h"

//跳跃游戏
//TL
class Solution1 {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            if (dp[i] == false) continue;
            for (int j = 1; j <= nums[i]; ++j) {
                if (i + j >= n) break;
                dp[i + j] = true;
            }
        }
        return dp[n - 1];
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int rightMost = 0;
        for (int i = 0; i < n; ++i) {
            if (i <= rightMost) {
                rightMost = max(rightMost, i + nums[i]);
                if (rightMost >= n - 1) return true;
            }
        }
        return false;
    }
};