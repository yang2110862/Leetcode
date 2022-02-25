#include "header.h"

// 每日温度

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                int pre = stk.top();
                ans[pre] = i - pre;
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};