from typing import List
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        parents = dict()
        ans = []
        def findParents(node: TreeNode):
            if (node.left != None):
                parents[node.left] = node
                findParents(node.left)
            if (node.right != None):
                parents[node.right] = node
                findParents(node.right)
        def findAns(node: TreeNode, prev: TreeNode, depth, k):
            if (node == None):
                return
            if (depth == k):
                ans.append(node.val)
                return
            if (node.left != prev):
                findAns(node.left, node, depth + 1, k)
            if (node.right != prev):
                findAns(node.right, node, depth + 1, k)
            #相较与C++不同，这里需要加上node in parents
            if node in parents and parents[node] != prev:
                findAns(parents[node], node, depth + 1, k)
        findParents(root)
        findAns(target, None, 0, k)
        return ans


