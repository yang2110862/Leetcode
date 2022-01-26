#include "header.h"

//相交链表

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        bool flag1 = true;
        bool flag2 = true;
        ListNode* p1 = headA, *p2 = headB;
        while (p1 && p2) {
            if (p1 == p2) return p1;
            p1 = p1->next;
            p2 = p2->next;
            if (p1 == nullptr && flag1) {
                flag1 = false;
                p1 = headB;
            }
            if (p2 == nullptr && flag2) {
                flag2 = false;
                p2 = headA;
            }
        }
        return nullptr;
    }
};

ListNode