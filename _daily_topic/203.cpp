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
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val) head = head->next;
        if (head == nullptr) return nullptr;
        ListNode* first = new ListNode;
        ListNode* second = new ListNode;
        first->next = head;
        second = head;
        while(second) {
            if (second->val == val) {
                first->next = second->next;
            } else {
                first = second;
            }
            second = second->next;
        }
        return head;
    }
};
