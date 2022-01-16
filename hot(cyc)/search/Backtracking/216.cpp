#include "header.h"

class Solution {
private:
    void backtrace(int k, int n, vector<vector<int>>& ans, vector<int>& currSol, int curSum, int curNum) {
        if (currSol.size() == k && curSum == n) {
            ans.push_back(currSol);
            return;
        }
        if (currSol.size() > k) {
            return;
        }
        for (int i = curNum; i <= 9; ++i){
            curSum += i;
            if (curSum > n) {
                break;
            }
            currSol.push_back(i);
            backtrace(k, n, ans, currSol, curSum, i + 1);
            currSol.pop_back();
            curSum -= i;
        }
        return;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> currSol;
        backtrace(k, n, ans, currSol, 0, 1);
        return ans;
    }
};