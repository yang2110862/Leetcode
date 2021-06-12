#include "header.h"

//dp
class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1);
        int ans = nums[0];     
        for (int i = 1; i <= n; ++i) {
            dp[i] = max(dp[i - 1] + nums[i - 1], nums[i - 1]);       //可不用数组，降维
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

//分治    线段树


class Solution {
private:
    struct Status {
        int lsum, rsum, msum, tsum;
    };
    Status join(Status l, Status r) {
        int lsum = max(l.lsum, l.tsum + r.lsum);
        int rsum = max(r.rsum, l.rsum + r.tsum);
        int msum = max(max(l.msum, r.msum), l.rsum + r.lsum);
        int tsum = l.tsum + r.tsum;
        return {lsum, rsum, msum, tsum};
    }
    Status get(vector<int>& nums, int l, int r) {
        if (l == r) return {nums[l], nums[l], nums[l], nums[l]};
        int mid = (l + r) >> 1;
        Status left = get(nums, l, mid);
        Status right = get(nums, mid + 1, r);
        return join(left, right);
    }
public:
    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).msum;
    }
};