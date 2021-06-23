#include "header.h"

class Solution {
private:
    unordered_map<int, int> mp;
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (mp.count(nums[i])) return nums[i];
            else ++mp[nums[i]];
        }
    }
};