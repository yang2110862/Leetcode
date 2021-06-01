#include "header.h"

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 1) return true;
        if (n < 4)  return false;
        int sqr = sqrt(n);
        return (n & -n) == n && (sqr * sqr == n);      
    }
};