#include "header.h"
//和相同的二元子数组 hash + mp + 前缀和

class Solution {
private:
    unordered_map<int, int> mp;
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0;
        int pre = 0;
        mp[0] = 1;
        for (auto x : nums) {
            pre += x;
            sum += mp.count(pre - goal) ? mp[pre - goal] : 0;
            ++mp[pre];
        }
        return sum;
    }
};