#include "header.h"

//爬楼梯

class Solution {
public:
    int climbStairs(int n) {
        int p1 = 1;
        int p2 = 1;
        if (n == 1) return 1;
        int ans;
        for (int i = 2; i <= n; ++i) {
            ans = p1 + p2;
            p1 = p2;
            p2 = ans;
        }
        return ans;
    }
};