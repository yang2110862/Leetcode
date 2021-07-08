#include "header.h"

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int pre = 0;
        map<int, int> hash;
        int ans = 0;
        hash[0] = 1;
        for (auto num : nums) {
            pre += num;
            if (hash.find(pre - k) != hash.end()) {
                ans += hash[pre - k];
            }
            hash[pre]++;
        }
        return ans;
    }
};
