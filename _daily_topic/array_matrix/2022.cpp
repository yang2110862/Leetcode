#include "header.h"

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        int len = original.size();
        if (len < m * n) return ans;
        int num = 0;
        for (int i = 0; i < m; ++i) {
            vector<int> row;
            for (int j = 0; j < n; ++j) {
                row.push_back(original[num++]);
            }
            ans.emplace_back(row);
        }
        return ans;
    }
};
