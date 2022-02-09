#include "header.h"

//逆波兰表达式求值

class Solution {
private:
    bool isDigit(const string& token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") return false;
        else return true;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (auto const& token : tokens) {
            if (isDigit(token)) {
                nums.push(stoi(token));
            } else {
                int second = nums.top();
                nums.pop();
                int first = nums.top();
                nums.pop();
                if (token == "+") {
                    nums.push(first + second);
                } else if (token == "-") {
                    nums.push(first - second);
                } else if (token == "/") {
                    nums.push(first / second);
                } else {
                    nums.push(first * second);
                }
            }
        }
        return nums.top();
    }
};