from typing import List
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution:
    mp = dict()
    def copyRandomList(self, head: Node):
        if head == None:
            return None
        if head in self.mp:
            return self.mp.get(head)
        newHead = Node(x = head.val)
        self.mp[head] = newHead
        newHead.next = self.copyRandomList(head.next)
        newHead.random = self.copyRandomList(head.random)
        return newHead