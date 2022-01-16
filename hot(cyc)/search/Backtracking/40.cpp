#include "header.h"

class Solution {
private:
    void backtrace(vector<int>& candidates, int num, vector<vector<int>>& ans, int curSum, int curNum, int target, vector<int>& curSol, vector<bool> marked) {
        if (curSum == target) {
            ans.push_back(curSol);
            return;
        }
        for (int i = curNum; i < num; ++i) {
            if (i > 0 && candidates[i] == candidates[i - 1] && !marked[i - 1]) {
                continue;
            }
            curSum += candidates[i];
            if (curSum > target) {
                break;
            }
            curSol.push_back(candidates[i]);
            marked[i] = 1;
            backtrace(candidates, num, ans, curSum, i + 1, target, curSol, marked);
            curSum -= candidates[i];
            curSol.pop_back();
            marked[i] = 0;
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int num = candidates.size();
        vector<vector<int>> ans;
        int curSum = 0;
        vector<int> curSol;
        vector<bool> marked(num, 0);
        backtrace(candidates, num, ans, curSum, 0, target, curSol, marked);
        return ans;
    }
};