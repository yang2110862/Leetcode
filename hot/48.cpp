#include "header.h"

// 旋转图像

class Solution1 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        auto matrix_new = matrix;
        for (int j = n - 1; j >= 0; --j) {
            for (int i = 0; i < n; ++i) {
                matrix_new[i][j] = matrix[n - j - 1][i];
            }
        }
        matrix = matrix_new;
    }
};


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < (n + 1) / 2; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                // int temp = matrix[i][j];
                // matrix[i][j] = matrix[n - j - 1][i];
                int temp = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};