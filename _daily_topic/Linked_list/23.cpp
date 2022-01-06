#include "header.h"

struct ListNode {    
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//分治合并
class Solution {
private: 
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* ans = new ListNode();
        ListNode* head = ans;
        while (a || b) {
            if (a == nullptr) {
                head->next = b;
                break;
            } else if (b == nullptr) {
                head->next = a;
                break;
            } else if (a->val < b->val) {
                head->next = a;
                a = a->next;
                head = head->next;
            } else {
                head->next = b;
                b = b->next;
                head = head->next;
            }
        }
        return ans->next;
    }
    ListNode* divide(vector<ListNode*>& lists, int l, int r) {
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        if (l == r - 1) return mergeTwoLists(lists[l], lists[r]);
        int mid = (l + r) >> 1;
        return mergeTwoLists(divide(lists, l, mid), divide(lists, mid + 1, r));
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return divide(lists, 0, lists.size() - 1);
    }
};