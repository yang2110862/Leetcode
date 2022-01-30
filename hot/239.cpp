#include "header.h"

//滑动窗口最大值


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            pq.push(make_pair(nums[i], i));
        }
        for (int i = 0; i < n - k + 1; ++i) {
            while (pq.top().second < i) {
                pq.pop();
            }
            ans.push_back(pq.top().first);
            if (i + k < n) {
                pq.push(make_pair(nums[i + k], i + k));
            }
        }
        return ans;
    }
};