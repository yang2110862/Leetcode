#include "header.h"

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(3), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode;
        ListNode* head = newHead;
        while (l1 || l2) {
            while (l1 && l2) {
                if (l1->val >= l2->val) {
                    int temp = l1;
                    l1->next = nullptr;
                    head->next = temp;
                    head = head->next;
                } else {

                }
            }
        }
    }
};
