from typing import List

class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        def getRow(label: int):
            row, start = 1, 1
            while (start * 2 <= label):
                row += 1
                start *= 2
            return row
        def getReverse(label: int, row: int):
            return (1 << row - 1) + (1 << row) - 1 - label
        row = getRow(label)
        if row & 1 == 1:
            label = getReverse(label)
        ans = []
        while row > 0:
            if row & 1 == 1:
                ans.append(getReverse(label, row))
            else:
                ans.append(label)
            row -= 1
            label >>= 1
        reversed(ans)
        return ans