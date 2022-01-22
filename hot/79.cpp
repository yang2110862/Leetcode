#include "header.h"

//单词搜索

class Solution {
private:
    vector<vector<int>> dirs{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    string word;
    int len;
    bool backtrace(const vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int column, int index) {
        if (index == len) return true;
        for (auto dir : dirs) {
            int new_row = row + dir[0];
            int new_column = column + dir[1];
            if (new_row < 0 || new_row >= board.size() || new_column < 0 || new_column >= board[0].size()) continue;
            if (!visited[new_row][new_column] && board[new_row][new_column] == word[index]) {
                visited[new_row][new_column] = true;
                if (backtrace(board, visited, new_row, new_column, index + 1)) return true;
                visited[new_row][new_column] = false;
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->word = word;
        len = word.size();
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (backtrace(board, visited, i, j, 1)) {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution test;
    vector<vector<char>> board{{'A','B'}, {'S', 'F'}};
    string word = "ABF";
    cout << test.exist(board, word);
}