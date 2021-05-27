#include "header.h"

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        while(x || y) {
            if ((x ^ y) & 1) {
                ++res;
            }
            x >>= 1;
            y >>= 1;
        }
    }
};