#include "header.h"

//WA  未考虑数字重复的情况
class Solution {
private:
    unordered_map<int, int> index;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            index[nums[i]] = i;
        }
        sort(nums.begin(), nums.end());
        int p1 = 0, p2 = n - 1;
        while (p1 < p2) {
            int sum = nums[p1] + nums[p2];
            if (sum == target) {
                return {index[nums[p1]], index[nums[p2]]};
            } else if (sum > target) {
                --p2;
            } else {
                ++p1;
            }
        }
        return {};
    }
};

class Solution {
private:
    unordered_map<int, int> index;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            auto it = index.find(target - nums[i]);
            if (it != index.end()) {
                return {it->second, i};
            } else {
                index[nums[i]] = i;
            }
        }
        return {};
    }
};