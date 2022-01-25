#include "header.h"

//环形链表

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode* fastP = head;
        ListNode* slowP = head;
        while (fastP && fastP->next) {
            fastP = fastP->next->next;
            slowP = slowP->next;
            if (slowP == fastP) return true;
        }
        return false;
    }
};