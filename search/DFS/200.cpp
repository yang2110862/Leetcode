#include "header.h"

class Solution {
private:
    int dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j>= grid[0].size() || grid[i][j] == '0') {
            return 0;
        }
        int di[4] = {0, 0, 1, -1};
        int dj[4] = {1, -1, 0, 0};
        grid[i][j] = '0';
        int ans = 1;
        for (int index = 0; index < 4; ++index) {
            int nextI = i + di[index];
            int nextJ = j + dj[index];
            ans += dfs(grid, nextI, nextJ);
        }
        return ans;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int num = dfs(grid, i, j);
                if (num > 0) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};