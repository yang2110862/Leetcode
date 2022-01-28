#include "header.h"
//岛屿数量

class Solution {
private:
    int m, n;
    vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<bool>> visited;
    void backtrace(const vector<vector<char>>& grid, int row, int column) {
        if (row < 0 || column < 0 || row >= m || column >= n) {
            return;
        }
        if (visited[row][column] || grid[row][column] == '0') return;
        visited[row][column] = true;
        for (auto dir : dirs) {
            int new_row = row + dir[0];
            int new_column = column + dir[1];
            backtrace(grid, new_row, new_column);
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        visited.resize(m, vector<bool>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ++ans;
                    backtrace(grid, i, j);
                }
            }
        }
        return ans;
    }
};