#include "header.h"

struct ListNode {    
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* p1 = list1, *p2 = list2;
        ListNode* ans = head;
        while (p1 || p2) {
            if (p1 == nullptr) {
                ans->next = p2;
                break;
            } else if (p2 == nullptr) {
                ans->next = p1;
                break;
            } else if (p1->val < p2->val) {
                ans->next = p1;
                ans = ans->next;
                p1 = p1->next;
            } else {
                ans->next = p2;
                ans = ans->next;
                p2 = p2->next;
            }
        }
        return head->next;
    }
};