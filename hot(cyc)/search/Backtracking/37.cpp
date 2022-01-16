#include "header.h"

class Solution {
private:
    bool islegal(size_t k, vector<vector<char>>& board, int x, int y) {
        int m = board.size();
        int n = board[0].size();
        for (size_t i = 0; i < 9; ++i){
            if(board[x][i] == (k + '0')) {
                return false;
            }
            if(board[i][y] == (k + '0')) {
                return false;
            }
        }
        int cnt1 ;
        int cnt2 ;
        for (size_t i = 0, cnt1 = 0; cnt1 < 3; ++cnt1, ++i) {
            for (size_t j = 0, cnt2 = 0; cnt2 < 3; ++cnt2, ++j) {
                if (board[3 * (x / 3) + i][3 * (y / 3) + j] == (k + '0')){
                    return false;
                }
            }
        }
        return true;
    }
    bool backtrace(vector<vector<char>> &board, int x, int y, vector<vector<bool>>& marked) {
        int m = board.size();
        int n = board[0].size();
        if (x == m && y == 0) {
            return true;
        }
        for (size_t i = x; i < m; ++i) {
            bool flag;//....
            if (i != x) {
                y = 0;
            }
            for (size_t j = y; j < n; ++j) {
                if (j == 8) {
                    flag = 1;
                }
                if (marked[i][j] == 0){
                    continue;
                } else {
                    for (size_t k = 1; k <= 9; ++k) {
                        if (islegal(k, board, i, j)) {
                            board[i][j] = (k + '0');
                            if (j == n - 1) {
                                if (backtrace(board, i + 1, 0, marked)) {
                                    return true;
                                }
                            } else {
                                if (backtrace(board, i, j + 1, marked)) {
                                    return true;
                                }
                            }
                            board[i][j] = '.';
                        } else{
                            continue;
                        }
                    }
                    board[i][j] = '.';
                    return false;
                }
            }
            if (i == 8 && flag) {
                return true;
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> marked(board.size(), vector<bool>(board[0].size(), 0));
        for (size_t i = 0; i < 9; ++i) {
            for (size_t j = 0; j < 9; ++j) {
                if (board[i][j] == '.'){
                    marked[i][j] = 1;
                }
            }
        }
        bool ans = backtrace(board, 0, 0, marked);
    }
};