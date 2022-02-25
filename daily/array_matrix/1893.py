from typing import List
class Solution:
    def isCovered(self, ranges: List[List[int]], left: int, right: int) -> bool:
        diff = [0] * 52
        for left, right in ranges:
            diff[left] += 1
            diff[right + 1] -= 1
        curr = 0
        for i in range(1, right):
            curr += diff[i]
            if i >= left and curr <= 0:
                return False
        return True