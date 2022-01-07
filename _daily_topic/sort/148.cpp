#include "header.h"


struct ListNode {    
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* findMindNode(ListNode* head, ListNode* tail) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }
        return slow;
    }
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* p1 = head1, *p2 = head2;
        ListNode* ans = new ListNode();
        ListNode* p = ans;
        while (p1 || p2) {
            if (p1 == nullptr) {
                p->next = p2;
                break;
            } else if (p2 == nullptr) {
                p->next = p1;
                break;
            } else if (p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
                p = p->next;
            } else {
                p->next = p2;
                p1 = p1->next;
                p = p->next;
            }
        }
        return ans->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }
    ListNode* sortList(ListNode* head, ListNode* tail) {
        if (head == tail) {
            return nullptr;
        }
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode* mid = findMindNode(head, tail);
        return(merge(sortList(head, mid), sortList(mid, tail)));
    }
};