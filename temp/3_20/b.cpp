#include "header.h"


class Solution {
private:
    int ans = 0;
    void backtrace(int m, int n, int row, int col) {
        if (m == row + 1 && n == col + 1) ++ans;
        if (row >= m || col >= n) return;
        backtrace(m, n, row + 1, col);
        backtrace(m, n, row, col + 1);
    }
public:
    int PathsCnt(int m, int n) {
        backtrace(m, n, 0, 0);
        return ans;
    }
};

int main() {
    Solution test;
    cout << test.PathsCnt(1, 1);
}