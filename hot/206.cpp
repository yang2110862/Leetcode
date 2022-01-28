#include "header.h"
//反转链表

class Solution {
private:
    ListNode* recursion(ListNode* node) {
        if (node->next == nullptr) return node;
        ListNode* tail = recursion(node->next);
        node->next->next = node;
        return tail;
    }
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* ans = recursion(head);
        head->next = nullptr;
        return ans;
    }
};