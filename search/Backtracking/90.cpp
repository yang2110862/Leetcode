#include "header.h"

class Solution {
private:
    void traceback(vector<int>&nums, int curNum, vector<vector<int>>& ans, vector<int>& curSol, vector<bool>& marked) {
        for (int i = curNum; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1] && !marked[i - 1]) {
                continue;
            }
            curSol.push_back(nums[i]);
            marked[i] = 1;
            ans.push_back(curSol);
            traceback(nums, i + 1, ans, curSol, marked);
            curSol.pop_back();
            marked[i] = 0;
        }
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curSol;
        vector<vector<int>> ans;
        ans.push_back(curSol);
        vector<bool> marked(nums.size(), 0);
        traceback(nums, 0, ans, curSol, marked);
        return ans;
    }
};