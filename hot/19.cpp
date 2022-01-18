#include "header.h"

//删除链表的倒数第 N 个结点

class Solution {
private:
    int numOfNode(ListNode* head) {
        int n = 0;
        while (head) {
            ++n;
            head = head->next;
        }
        return n;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sum = numOfNode(head);
        int del = sum - n + 1;
        if (del == 1) return head->next;
        int num = 1;
        ListNode* p = head;
        while (p) {
            ++num;
            if (num == del) {
                p->next = p->next->next;
                return head;
            }
            p = p->next;
        }
        return nullptr;
    }
};