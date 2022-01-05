#include "header.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int step1 = n, step2 = m - 1;
        int x = 0, y = -1;
        vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0;
        vector<int> ans;
        int num = 0;
        int step = (num & 1) ? step2-- : step1--;
        while (step) {
            for (int i = 0; i < step; ++i) {
                x += dirs[dir].first;
                y += dirs[dir].second;
                ans.push_back(matrix[x][y]);
            }
            ++num;
            step = (num & 1) ? step2-- : step1--;
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<vector<int>> matrix{{1,2,3}, {4,5,6}, {7,8,9}};
    auto x = test.spiralOrder(matrix);
}