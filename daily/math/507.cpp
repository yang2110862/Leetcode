#include "header.h"

// 完美数

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) return false;
        int n = sqrt(num);
        int sum = 1;
        for (int i = 2; i <= n; ++i) {
            if (num % i == 0) {
                sum += i;
                sum += num / i;
            }
        }
        if (n * n == num) sum -= n;
        if (sum == num) return true;
        else return false;
    }
};
