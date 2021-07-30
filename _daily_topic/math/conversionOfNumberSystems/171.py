from typing import List
class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        mutiple = 1
        n = len(columnTitle)
        ans = 0
        for i in range(n):
            ans += mutiple * (columnTitle[i] - 'A' - 1)
            mutiple *= 26
        return ans