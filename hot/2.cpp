#include "header.h"
// 2.两数相加
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode;
        ListNode* cur = head;
        while (l1 || l2 || carry) {
            int num1 = l1 == nullptr ? 0 : l1->val;
            int num2 = l2 == nullptr ? 0 : l2->val;
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            ListNode* temp = new ListNode(sum % 10);
            cur->next = temp;
            cur = temp;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return head->next;
    }
};