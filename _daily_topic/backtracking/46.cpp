#include "header.h"
// 全排列
class Solution {
private:
    vector<vector<int>> ans;
    void backtracking(vector<int>& nums, vector<bool>& visited, vector<int>& num, int n) {
        if (num.size() == n) {
            ans.push_back(num);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            num.push_back(nums[i]);
            visited[i] = true;
            backtracking(nums, visited, num, n);
            num.pop_back();
            visited[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        vector<int> num;
        backtracking(nums, visited, num, n);
        return ans;
    }
};