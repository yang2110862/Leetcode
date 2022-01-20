#include "header.h"

//组合总和

class Solution {
private:
    vector<vector<int>> ans;
    void backtrace(const vector<int>& candidates, int target, vector<int> combination, int sum, int index) {
        if (sum == target) {
            ans.push_back(combination);
            return;
        }
        if (sum > target) return;
        for (auto x : candidates) {
            if (index >= 0 && x < combination[index]) continue;
            combination.push_back(x);
            backtrace(candidates, target, combination, sum + x, index + 1);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combinationSum;
        int sum = 0;
        int index = -1;
        backtrace(candidates, target, combinationSum, sum, index);
        return ans;
    }
};