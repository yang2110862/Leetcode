from typing import List
from collections import defaultdict
#有错
class Solution:
    adj = defaultdict(list)
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        for a, b in adjacentPairs:
            self.adj[a].append(b)
            self.adj[b].append(a)
        n = len(adjacentPairs) + 1
        ans = [0] * n
        for e, arr in self.adj.items():
            if len(arr) == 1:
                ans[0] = e
                break
        ans[1] = self.adj[ans[0]][0]
        for i in range(2, n):
            temp = self.adj[ans[i - 1]]
            ans[i] = temp[0] if ans[i - 2] == temp[1] else temp[1]
        return ans