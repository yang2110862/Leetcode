#include <iostream>
using namespace std;
//经典判圈法
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        while(head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {   //思考这个条件
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};