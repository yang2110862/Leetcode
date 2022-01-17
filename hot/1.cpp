#include "header.h"
//两数之和
class Solution {
private:
    unordered_map<int, int> index;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int t = target - nums[i];
            if (index.count(t)) {
                return {index[t], i};
            }
            index[nums[i]] = i;
        }
        return {};
    }
};