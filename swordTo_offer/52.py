class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution1:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        st = set()
        while headA:
            st.add(headA)
            headA = headA.next
        while headB:
            if headB in st:
                return headB
            headB = headB.next
        return None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        pA, pB = headA, headB
        while pA != pB:
            pA = pA.next if pA else headB
            pB = pB.next if pB else headA
        return pA