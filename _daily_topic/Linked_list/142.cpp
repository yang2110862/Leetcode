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
    bool isCycle(ListNode* head) {
        if (head == nullptr) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
        return false;
    }
    unordered_set<ListNode*> st;
public:
    ListNode *detectCycle(ListNode *head) {
        if (isCycle(head)) {
            while (head) {
                if (st.count(head)) return head;
                else st.insert(head);
                head = head->next;
            }
        } 
        return nullptr;
    }
};