#include "header.h"
//第 N 个泰波那契数
class Solution1 {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        vector<int> dp(n + 1);
        int a = 0, b = 1, c = 1;
        for (int i = 3; i <= n; ++i) {
            int temp = a + b + c;
            a = b;
            b = c;
            c = temp;
        }
        return c;
    }
};

//矩阵快速幂

class Solution {
private:
    vector<vector<long>> multiply(vector<vector<long>>& a, vector<vector<long>>& b) {
        vector<vector<long>> res;
        for (int i = 0; i < 3; ++i) {
            vector<long> temp;
            for (int j = 0; j < 3; ++j) {
                int num = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
                temp.push_back(num);
            }
            res.push_back(temp);
        }
        return res;
    }
    vector<vector<long>> matrixPow(vector<vector<long>>& arr, int n) {
        vector<vector<long>> res{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        while (n) {
            if (n & 1) {
                res = multiply(res, arr);
            }
            arr = multiply(arr, arr);
            n >>= 1;
        }
        return res;
    }
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1;
        vector<vector<long>> matrix{{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
        vector<int> b{1, 1, 0};
        auto arr = matrixPow(matrix, n - 2);
        return arr[0][0] + arr[0][1];
    }
};
