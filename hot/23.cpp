#include "header.h"

//合并K个升序链表

class Solution {
private:
    ListNode* mergeTwo(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* p = head;
        while (list1 || list2) {
            if (list1 == nullptr) {
                p->next = list2;
                break;
            } 
            if (list2 == nullptr) {
                p->next = list1;
                break;
            }
            if (list1->val < list2->val) {
                p->next = list1;
                list1 = list1->next;
                p = p->next;
            } else {
                p->next = list2;
                list2 = list2->next;
                p = p->next;
            }
        }
        return head->next;
    }
    ListNode* mergeSort(vector<ListNode*>& lists, int left, int right) {
        if (left == right) return lists[left];
        else if (left == right - 1) return mergeTwo(lists[left], lists[right]);
        else {
            int mid = (left + right) >> 1;
            return mergeTwo(mergeSort(lists, left, mid), mergeSort(lists, mid + 1, right));
        }
        return nullptr;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return nullptr;
        return mergeSort(lists, 0, n - 1);
    }
};