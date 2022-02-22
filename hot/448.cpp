#include "header.h"

//找到所有数组中消失的数字

class Solution1 {
private:
    unordered_map<int, int> cnt;
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (auto x : nums) {
            ++cnt[x];
        }
        vector<int> ans;
        for (int i = 1; i <= n; ++i) {
            if (cnt.find(i) == cnt.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
//原地修改
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (auto& num : nums) {
            int x = (num - 1) % n;
            nums[x] += n;
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= n) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
