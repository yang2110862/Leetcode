#include "header.h"

class Solution {
private:
    vector<vector<int>> ans;
    void backtrace(vector<int>& a, int index, int n, vector<int> subSet) {
        if (index == n) {
            ans.push_back(subSet);
            return;
        }
        subSet.push_back(a[index]);
        backtrace(a, index + 1, n, subSet);
        subSet.pop_back();
        backtrace(a, index + 1, n, subSet);
        return;
    }
public:
    vector<vector<int> > SubSets(vector<int>& a) {
        backtrace(a, 0, a.size(), vector<int>());
        return ans;
    }
};