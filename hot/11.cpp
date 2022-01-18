#include "header.h"

// 盛最多水的容器

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = height.size() - 1;
        int area = 0;
        while (l < r) {
            int width = r - l;
            int sum = min(height[l], height[r]) * width;
            area = max(sum, area);
            if (height[l] > height[r]) {
                --r;
            } else {
                ++l;
            }
        }
        return area;
    }
};