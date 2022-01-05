#include "header.h"

class Solution {
private:
    unordered_set<int> st;
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (st.count(nums[i])) return true;
            else st.insert(nums[i]);
        }
        return false;
    }
};