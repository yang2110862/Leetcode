#include "header.h"

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        int x = 0, y = n - 1;
        while (x >= 0 && y >= 0 && x < m && y < n) {
            if (matrix[x][y] == target) return true;
            else if (matrix[x][y] > target) --y;
            else ++x;
        }
        return false;
    }
};