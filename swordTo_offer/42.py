from typing import List
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0] * (n + 1)
        ans = nums[0]
        for i in range(1, n + 1) :
            dp[i] = max(dp[i - 1] + nums[i - 1], nums[i - 1])
            ans = max(dp[i], ans)
        return ans


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        pre = 0
        ans = nums[0]
        for i in range(1, n + 1) :
            pre = max(pre + nums[i - 1], nums[i - 1]);
            ans = max(pre, ans)
        return ans