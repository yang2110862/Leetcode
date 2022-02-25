from typing import List
class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        left, right, total, res = 0, 1, 0, 1
        while right < n :
            total = total + (nums[right] - nums[right - 1]) * (right - left)
            while total > k :
                total = total - (nums[right] - nums[left])
                left = left + 1
            res = max(res, right - left + 1)
            right = right + 1
        return res