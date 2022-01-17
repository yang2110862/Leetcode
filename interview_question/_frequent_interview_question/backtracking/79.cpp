#include "header.h"

class Solution {
    bool backtrack(vector<vector<bool>>& visited, vector<vector<char>>& board, string& word, int m, int n, int index) {
        if (board[m][n] != word[index]) return false;
        if (index == word.size() - 1) return true;
        vector<pair<int, int>> dirction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        visited[m][n] = true;
        for (int i = 0; i < 4; ++i) {
            int new_m = m + dirction[i].first;
            int new_n = n + dirction[i].second;
            if (new_m > board.size() - 1 || new_n > board[0].size() - 1 || new_m < 0 || new_n < 0) continue;
            if (!visited[new_m][new_n]) {
                if (backtrack(visited, board, word, new_m, new_n, index + 1)) return true;
            }
        }
        visited[m][n] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (backtrack(visited, board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};