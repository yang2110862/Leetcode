#include "header.h"

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        if (n < 1) return false;
        for (int i = 0; i <= 32; ++i) {
            if (n & 1) {
                ++cnt;
            }
            n >>= 1;
        }       
        if (cnt == 1) return true;
        else return false;
    }
};