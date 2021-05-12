#include "header.h"

class Solution {
private:
    void traceback(vector<int>&nums, int curNum, vector<vector<int>>& ans, vector<int>& curSol) {
        for (int i = curNum; i < nums.size(); ++i) {
            curSol.push_back(nums[i]);
            ans.push_back(curSol);
            traceback(nums, i + 1, ans, curSol);
            curSol.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curSol;
        vector<vector<int>> ans;
        ans.push_back(curSol);
        traceback(nums, 0, ans, curSol);
        return ans;
    }
};