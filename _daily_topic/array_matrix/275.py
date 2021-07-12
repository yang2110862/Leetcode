from typing import List
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        h = 0
        i = len(citations) - 1
        while i >= 0 and citations[i] > h :
            h += 1
            i -= 1
        return h

