#include "header.h"

class Solution {
private:
    void backtrace(vector<int>& candidates, int num, vector<vector<int>>& ans, int curSum, int curNum, int target, vector<int>& curSol) {
        if (curSum == target) {
            ans.push_back(curSol);
            return;
        }
        for (int i = curNum; i < num; ++i) {
            curSum += candidates[i];
            if (curSum > target) {
                break;
            }
            curSol.push_back(candidates[i]);
            backtrace(candidates, num, ans, curSum, i, target, curSol);
            curSum -= candidates[i];
            curSol.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int num = candidates.size();
        vector<vector<int>> ans;
        int curSum = 0;
        vector<int> curSol;
        backtrace(candidates, num, ans, curSum, 0, target, curSol);
        return ans;
    }
};