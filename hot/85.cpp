#include "header.h"
//最大矩形
//勉强通过不超时
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int p = j;
                while (p < n && matrix[i][p] == '1') {
                    ++p;
                }
                int width = p - j;
                int height = INT_MAX;
                for (int column = j; column < p; ++column) {
                    int p2 = i;
                    while (p2 < m && matrix[p2][column] == '1') {
                        ++p2;
                    }
                    height = min(height, p2 - i);
                    ans = max(ans, height * (column - j + 1));
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<vector<char>> matrix{{'1', '1'}, {'1', '0'}};
    cout << test.maximalRectangle(matrix);
}
