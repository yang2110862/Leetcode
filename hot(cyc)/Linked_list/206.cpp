#include "header.h"

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* ans = new ListNode;
        while (head) {
            ListNode* temp = head->next;
            head->next = ans->next;
            ans->next = head;
            head = temp;
        }
        return ans->next;
    }
};