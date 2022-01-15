#include "header.h"


class Solution {
private:
    vector<vector<int>> ans;
    void backtracking(const vector<int>& nums, int index, int n, vector<int> subset) {
        if (index == n) return;
        for (int i = index; i < n; ++i) {
            subset.push_back(nums[i]);
            ans.push_back(subset);
            backtracking(nums, i + 1, n, subset);
            subset.erase(subset.end() - 1);
        }
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> subset;
        backtracking(nums, 0, n, subset);
        ans.push_back({});
        return ans;
    }
};

int main() {
    Solution test;
    vector<int> nums{1,2};
    auto x = test.subsets(nums);
}