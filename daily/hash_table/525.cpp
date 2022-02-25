#include "header.h"

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int pre = 0;
        int ans = 0;
        mp[0] = -1;
        for (int i = 0; i < n; ++i) {
            pre += nums[i] == 1 ? 1 : -1;
            if (mp.find(pre) != mp.end()) {
                ans = max(ans, i - mp[pre]);
            } else {
                mp[pre] = i;
            }
        }
        return ans;
    }
};
