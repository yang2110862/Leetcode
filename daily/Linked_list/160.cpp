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
    unordered_set<ListNode*> st;
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA, *p2 = headB;
        while (p1 || p2) {
            if (p1 == nullptr) {
                while (p2) {
                    if (st.count(p2)) return p2;
                    p2 = p2->next;
                }
            }
            if (p2 == nullptr) {
                while (p1) {
                    if (st.count(p1)) return p1;
                    p1 = p1->next;
                }
            }
            if (p1 == p2) return p1;
            if (st.count(p1)) return p1;
            if (st.count(p2)) return p2;
            st.insert(p1);
            st.insert(p2);
            p1 = p1->next;
            p2 = p2->next;
        }
        return nullptr;
    }
};