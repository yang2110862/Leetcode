#include "header.h"

//接雨水

class Solution {
public:
    int trap(vector<int>& height) {
        stack<pair<int, int>> stk;
        int n = height.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (stk.empty()) {
                stk.emplace(make_pair(i, height[i]));
                continue;
            }
            if (height[i] < stk.top().second) {
                stk.emplace(make_pair(i, height[i]));
            } else {
                while (!stk.empty() && height[i] > stk.top().second) {
                    auto top = stk.top();
                    stk.pop();
                    if (!stk.empty()) {
                        auto left = stk.top();
                        int w = i - left.first - 1;
                        int h = min(left.second, height[i]) - top.second;
                        sum += w * h;
                    }
                }
                stk.emplace(make_pair(i, height[i]));
            }
        }
        return sum;
    }
};

int main() {
    Solution test;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << test.trap(height);
}