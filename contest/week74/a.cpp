#include "header.h"

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i += 2) {
            if (nums[i] != nums[i + 1]) return false;
        }        
        return true;
    }
};