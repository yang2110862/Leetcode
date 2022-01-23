#include "header.h"

//柱状图中最大的矩形

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int n = heights.size();
        int ans = INT_MIN;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int index = stk.top();
                int height = heights[index];
                stk.pop();
                int right = i;
                int left = stk.empty() ? 0 : stk.top() + 1;
                int width = right - left;
                ans = max(ans, width * height);
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            int right = n;
            int height = heights[stk.top()];
            stk.pop();
            int left = stk.empty() ? 0 : stk.top() + 1;
            int width = right - left;
            ans = max(ans, width * height);
        }
        return ans;
    }
};