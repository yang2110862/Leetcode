#include "header.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int number = 1;
        vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0;
        int x = 0, y = -1;
        int step1 = n, step2 = n - 1;
        int num = 0;
        int step = (num & 1) ? step2-- : step1--;
        while (step) {
            for (int i = 0; i < step; ++i) {
                x = x + dirs[dir].first;
                y = y + dirs[dir].second;
                ans[x][y] = number++;
            }
            ++num;
            step = (num & 1) ? step2-- : step1--;
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};