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
            if (i > 0 && nums[i] == nums[i - 1] && !marked[i - 1]) { //重复出现的数字只填入第一次碰到时的即可
                continue;
            }
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> marked(size, 0);
        backtrace(nums, marked, ans, temp);
        return ans;
    }
};