#include "header.h"
//  旋转链表
struct ListNode {    
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    int lenOfList(ListNode* l) {
        int len = 0;
        while (l) {
            l = l->next;
            len++;
        }
        return len;
    }
    ListNode* findTail(ListNode* head) {
        if (!head) return nullptr;
        while (head->next != nullptr) {
            head = head->next;
        }
        return head;
    }
    ListNode* findKthNode(ListNode* head, int k) {
        for (int i = 1; i < k; ++i) {
            head = head->next;
        }
        return head;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len = lenOfList(head);
        if (len == 0) return nullptr;
        int step = k % len;
        ListNode* beg = head;
        ListNode* end = findTail(head);
        if (step == 0) return head;
        else {
            ListNode* mid = findKthNode(head, len - step);
            end->next = beg;
            beg = mid->next;
            mid->next = nullptr;
        }
        return beg;
    }
};