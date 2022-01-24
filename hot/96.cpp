#include "header.h"

//不同的二叉搜索树
//**递归可以转为DP
class Solution {
private:
    unordered_map<int, int> cnt;
public:
    int numTrees(int n) {
        if (n == 1 || n == 0) return 1;
        if (cnt.count(n)) return cnt[n];
        int sum = 0;
        for (int left = 0; left < n; ++left) {
            sum += numTrees(left) * numTrees(n - 1 - left);
        }
        cnt[n] = sum;
        return sum;
    }
};