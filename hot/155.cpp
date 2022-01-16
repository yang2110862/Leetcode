#include "header.h"

// 155 最小栈

class MinStack {
private:
    stack<int> stk1;
    stack<int> stk2;
public:
    MinStack() {
    }
    
    void push(int val) {
        stk1.push(val);
        if (stk2.empty()) {
            stk2.push(val);
        } else {
            int temp = min(stk2.top(), val);
            stk2.push(temp);
        }
    }
    
    void pop() {
        stk1.pop();
        stk2.pop();
    }
    
    int top() {
        return stk1.top();
    }
    
    int getMin() {  
        return stk2.top();
    }
};
