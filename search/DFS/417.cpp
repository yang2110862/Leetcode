#include "header.h"

class Solution {
private:
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& marked, int i, int j) {
        if (i < 0 || j < 0 || i == matrix.size() || j == matrix[0].size() || marked[i][j] == 1) {
            return ;
        }
        marked[i][j] = 1;
        int di[4] = {0, -1, 0, 1};
        int dj[4] = {1, 0, -1, 0};
        for (int index = 0; index < 4; ++index) {
            int newI = i + di[index];
            int newJ = j + dj[index];
            if (newI < 0 || newJ < 0 || newI == matrix.size() || newJ == matrix[0].size() || marked[newI][newJ] == 1) {
                continue;        //continue而不是return
            }
            if (matrix[newI][newJ] >= matrix[i][j]) {
                dfs(matrix, marked, newI, newJ);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return {};
        }
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> P(m, vector<bool>(n, 0));
        vector<vector<bool>> A(m, vector<bool>(n, 0));
        for (int i = 0; i < m; ++i) {
            dfs(matrix, P, i, 0);
            dfs(matrix, A, i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            dfs(matrix, P, 0, j);
            dfs(matrix, A, m - 1, j);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (P[i][j] & A[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};