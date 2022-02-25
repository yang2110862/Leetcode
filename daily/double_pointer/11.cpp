#include "header.h"

//盛最多水容器。
//为什么要用双指针，其中要考虑到数学证明。
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        long ans = 0;
        while (l < r) {
            long temp = min(height[l], height[r]) * (r - l);
            if (temp > ans) {
                ans = temp;
            }
            if (height[l] <= height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return ans;
    }
};
int main() {
    Solution test;

    return 0;
}