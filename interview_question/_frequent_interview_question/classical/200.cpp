#include "header.h"

class Solution {
private:
    vector<vector<int>> direction{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') return 0;
        grid[i][j] = '0';
        int ans = 1;
        for (auto& dir : direction) {
            ans += dfs(grid, i + dir[0], j + dir[1]);
        }
        return ans;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int num = dfs(grid, i, j);
                if (num > 0) ++ans;
            }
        }
        return ans;
    }
};