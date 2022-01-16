#include "header.h"

class Solution {
private:
    void backtrace(vector<int>& nums, vector<bool> marked, vector<vector<int>>& ans, vector<int>& temp){
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (!marked[i]) {
                temp.push_back(nums[i]);
                marked[i] = 1;
                backtrace(nums, marked, ans, temp);
                temp.pop_back();
                marked[i] = 0;
            }
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> marked(size, 0);
        backtrace(nums, marked, ans, temp);
        return ans;
    }
};