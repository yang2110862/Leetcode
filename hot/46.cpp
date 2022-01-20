#include "header.h"

//全排列

class Solution {
private:
    vector<vector<int>> ans;
    void backtrace(const vector<int>& nums, vector<bool>& visited, vector<int> combination, int n) {
        if (combination.size() == n) {
            ans.push_back(combination);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                continue;
            } else {
                combination.push_back(nums[i]);
                visited[i] = true;
                backtrace(nums, visited, combination, n);
                visited[i] = false;
                combination.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n);
        vector<int> combination;
        backtrace(nums, visited, combination, n);
        return ans;
    }
};