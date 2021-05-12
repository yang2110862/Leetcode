#include "header.h"

class Solution {
private:
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O') {
            return ;
        }
        board[i][j] = 'Y';
        int di[4] = {1, -1, 0, 0};
        int dj[4] = {0, 0, 1, -1};
        for (int index = 0; index < 4; ++index) {
            int newI = i + di[index];
            int newJ = j + dj[index];
            dfs(board, newI, newJ);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < n; ++i) {
            dfs(board, 0, i);
            dfs(board, m - 1, i);
        }
        for (int i = 0; i < m; ++i) {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'Y') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};