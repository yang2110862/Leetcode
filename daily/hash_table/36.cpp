#include "header.h"

class Solution {
private:
    unordered_map<int, unordered_set<char>> rows;
    unordered_map<int, unordered_set<char>> cols;
    unordered_map<int, unordered_set<char>> palaces;
    int compute_palace(int row, int col) {
        if (row < 3) {
            if (col < 3) return 1;
            else if (col < 6) return 2;
            else return 3;
        } else if (row < 6) {
            if (col < 3) return 4;
            else if (col < 6) return 5;
            else return 6;
        } else {
            if (col < 3) return 7;
            else if (col < 6) return 8;
            else return 9;
        }
        return -1;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;
                int palace = compute_palace(i, j);
                if (rows[i].count(c)) return false;
                else rows[i].insert(c);
                if (cols[j].count(c)) return false;
                else cols[j].insert(c);
                if (palaces[palace].count(c)) return false;
                else palaces[palace].insert(c);
            }
        }
        return true;
    }
};