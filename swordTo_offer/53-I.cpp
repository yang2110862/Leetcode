#include "header.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return end - beg;
    }
};