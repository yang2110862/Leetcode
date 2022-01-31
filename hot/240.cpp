#include "header.h"

// 搜索二维矩阵 II

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, column = n - 1;
        while (row < m && column >= 0) {
            int num = matrix[row][column];
            if (num == target) return true;
            else if (num > target) --column;
            else ++row;
        }
        return false;
    }
};