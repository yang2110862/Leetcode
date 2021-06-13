#include "header.h"
//动态规划
class Solution1 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; ++i) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
};
//单调栈
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        stack<int> stk;
        stk.push(0);
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            while(!stk.empty() && height[i] > height[stk.top()]) {
                int index = stk.top();
                stk.pop();
                if (stk.empty()) break;
                int width = (i - stk.top()) - 1;
                int high = min(height[i], height[stk.top()]) - height[index];
                ans += width * high;
            }
            stk.push(i);
        }
        return ans;
    }
};
