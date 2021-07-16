from typing import List
import bisect
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        beg = bisect.bisect_left(nums, target)
        end = bisect.bisect_right(nums, target)
        return end - beg