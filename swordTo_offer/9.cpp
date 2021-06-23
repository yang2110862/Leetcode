#include "header.h"

class CQueue {
    stack<int> stk1, stk2;
public:
    CQueue() {}
    
    void appendTail(int value) {
        stk1.push(value);
    }
    
    int deleteHead() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        if (stk2.empty()) return -1;
        else {
            int ans = stk2.top();
            stk2.pop();
            return ans;
        }
    }
};