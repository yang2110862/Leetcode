#include "header.h"

//环形链表 II

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;
        ListNode* fastP = head;
        ListNode* slowP = head;
        while (fastP && fastP->next) {
            fastP = fastP->next->next;
            slowP = slowP->next;
            if (slowP == fastP) {
                ListNode* ans = head;
                while (head != slowP) {
                    head = head->next;
                    slowP = slowP->next;
                }
                return head;
            }
        }
        return nullptr;
    }
};