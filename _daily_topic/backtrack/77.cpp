#include "header.h"

class Solution {
private:
    vector<vector<int>> ans;
    void vacktrack(vector<int>& arr, int cur, int k) {
        if (arr.size() == k) {
            ans.push_back(arr);
            return;
        }
        
    }
public:
    vector<vector<int>> combine(int n, int k) {

    }
};