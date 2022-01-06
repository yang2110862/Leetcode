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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        int carry = 0;
        ListNode* p1 = l1, *p2 = l2, *p = ans;
        while (p1 || p2 || carry) {
            int x = p1 == nullptr ? 0 : p1->val;
            int y = p2 == nullptr ? 0 : p2->val;
            int sum = x + y + carry;
            carry = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            if (p1) p1 = p1->next;
            if (p2) p2 = p2->next;
        }
        return ans->next;
    }
};