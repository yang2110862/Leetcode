#include "header.h"
//主要元素  投票法

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int cnt = 0;
        for (auto x : nums) {
            if (cnt == 0) candidate = x;
            if (candidate == x) ++cnt;
            else --cnt;
        }
        cnt = 0;
        int n = nums.size();
        for (auto x : nums) {
            if (x == candidate) ++cnt;
        }
        if (cnt > n / 2) return candidate;
        else return -1;
    }
};