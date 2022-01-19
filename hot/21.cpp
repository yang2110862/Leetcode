#include "header.h"
//合并两个有序链表

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* p = head;
        while (list1 || list2) {
            if (list1 == nullptr) {
                p->next = list2;
                break;
            } 
            if (list2 == nullptr) {
                p->next = list1;
                break;
            }
            if (list1->val < list2->val) {
                p->next = list1;
                list1 = list1->next;
                p = p->next;
            } else {
                p->next = list2;
                list2 = list2->next;
                p = p->next;
            }
        }
        return head->next;
    }
};