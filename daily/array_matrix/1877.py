from typing import List
class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        res = 0
        for i in range(0, n // 2):
            sum = nums[i] + nums[n - i - 1]
            res = max(res, sum)
        return res