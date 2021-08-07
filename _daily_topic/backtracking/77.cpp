#include "header.h"

class Solution {
private:
    vector<vector<int>> ans;
    void backtrack(vector<int>& arr, int cur, int k, int n) {
        if (arr.size() == k) {
            ans.push_back(arr);
            return;
        }
        for (int i = cur; i <= n; ++i) {
            arr.push_back(i);
            backtrack(arr, i + 1, k, n);
            arr.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> arr;
        backtrack(arr, 1, k, n);
        return ans;
    }
};