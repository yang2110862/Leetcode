#include "header.h"

class Solution {
private:
    static const int mod = 1000000007;
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        vector<long long> f(n + 1);
        f[0] = 0;
        f[1] = 1;
        for (int i = 2; i <= n; ++i) {
            f[i] = (f[i - 1] + f[i - 2]) % mod;
        }
        return f[n];
    }
};