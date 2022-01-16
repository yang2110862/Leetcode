#include "header.h"

class Solution {
private:
    void traceback(int n, int k, vector<vector<int>>& ans, vector<int>& curr, int cur) {
        if(curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        for (int i = cur; i < n; ++i) {
            curr.push_back(i + 1);
            traceback(n, k, ans, curr, i + 1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        traceback(n, k, ans, curr, 0);
        return ans;
    }
};