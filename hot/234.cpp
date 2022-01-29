#include "header.h"

//回文链表

class Solution {
private:
    ListNode* findMind(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        if (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverseLink(ListNode* node) {
        if (node->next == nullptr) return node;
        ListNode* tail = reverseLink(node->next);
        node->next->next = node;
        node->next = nullptr;
        return tail;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* mid = findMind(head);
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        if (l2 == nullptr) return true;
        mid->next = nullptr;
        l2 = reverseLink(l2);
        while (l1 && l2) {
            if (l1->val != l2->val) return false;
            l1 = l1->next;
            l2 = l2->next;
        }
        return true;
    }
};