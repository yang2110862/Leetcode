#include "header.h"

class Solution {
private:
    bool ans = 0;
    void backtrace(vector<vector<char>>& board, string& word, int cnt, int i, int j, vector<vector<bool>>& marked) {
        if (board[i][j] != word[cnt]) {
            return;
        } else if (cnt == word.size() - 1) {
            ans = 1;
            return;
        }
        marked[i][j] = 1;
        int di[4] = {0, 0, 1, -1};
        int dj[4] = {1, -1, 0, 0};
        for (int index = 0; index < 4; ++index) {
            if (ans) {
                return ;
            }
            int newI = i + di[index];
            int newJ = j + dj[index];
            if (newI < 0 || newJ < 0 || newI == board.size() || newJ == board[0].size() || marked[newI][newJ]) {
                continue;
            } else {
                backtrace(board, word, cnt + 1 ,newI, newJ, marked);
            }
        }
        marked[i][j] = 0;
        return;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> marked(m, vector<bool>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                backtrace(board, word, 0, i, j, marked);
                if (ans) {
                    return true;
                }
            }
        }
        return false;
    }
};