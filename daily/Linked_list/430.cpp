#include "header.h"
//430. 扁平化多级双向链表

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
private:
    stack<Node*> stk;
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        stk.push(head);
        Node* p1 = head;
        while (stk.size() >= 1) {
            if (p1->child) {
                if (p1->next) stk.push(p1->next);
                p1->next = p1->child;
                p1->child->prev = p1;
                p1 = p1->child;
                p1->prev->child = nullptr;
            } else if (p1->next) {
                p1 = p1->next;
            } else {
                if (stk.size() == 1) break;
                p1->next = stk.top();
                stk.top()->prev = p1;
                p1 = stk.top();
                stk.pop();
            }
        }
        return head;
    }
};