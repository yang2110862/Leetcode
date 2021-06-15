#include "header.h"

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(3), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* mergeTweoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode;
        ListNode* tail = ans;
        if (list1 == nullptr && list2 == nullptr) return nullptr;
        if (list1 == nullptr || list2 == nullptr) return list1 == nullptr ? list2 : list1;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;
        return ans->next;
    }
    ListNode* mergeLists(vector<ListNode*>& lists, int begin, int end) {
        if (begin == end) return lists[begin];
        ListNode* ans = new ListNode;
        int mid = (begin + end) >> 1;
        auto list1 = mergeLists(lists, begin, mid);
        auto list2 = mergeLists(lists, mid + 1, end);
        ans = mergeTweoLists(list1, list2);
        return ans;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode;
        return mergeLists(lists, 0, lists.size() - 1);
    }
};