#include "header.h"
//同余定理
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return false;
        unordered_map<int, int> mp;
        int pre = 0;
        mp[0] = -1;
        for (int i = 0; i < n; ++i) {
            pre = (pre + nums[i]) % k;
            if (mp.find(pre) != mp.end()) {
                if (i - mp[pre] >= 2) return true;
            } else {
                mp[pre] = i;
            }
        }
        return false;
    }
};