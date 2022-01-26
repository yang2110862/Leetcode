#include "header.h"

//排序链表

class Solution {
private:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* ans = new ListNode;
        ListNode* p = ans;
        ListNode* p1 = head1, *p2 = head2;
        while (p1 || p2) {
            if (p1 == nullptr) {
                p->next = p2;
                break;
            } else if (p2 == nullptr) {
                p->next = p1;
                break;
            } else {
                if (p1->val < p2->val) {
                    p->next = p1;
                    p = p->next;
                    p1 = p1->next;
                } else {
                    p->next = p2;
                    p = p->next;
                    p2 = p2->next;
                }
            }
        }
        return ans->next;
    }
    ListNode* mergeSort(ListNode* head, ListNode* tail) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != tail) {
            fast = fast->next;
            slow = slow->next;
            if (fast->next != tail) {
                fast = fast->next;
            }
        }
        ListNode* mid = slow;
        ListNode* first = mergeSort(head, mid);
        ListNode* second = mergeSort(mid, tail);
        return merge(first, second);
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head, nullptr);
    }
};

int main() {
    Solution test;
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(1);
    auto x = test.sortList(head);
}