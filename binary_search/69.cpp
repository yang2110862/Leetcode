#include "header.h"

class Solution {
public:
    int mySqrt(int x) {
        int low = 0, high = x;
        long long int m;
        while (low <= high) {
            m = low + (high - low) / 2;
            if (m * m == x || ((m + 1) * (m + 1) > x && m * m < x)) {
                return m;
            } else if (m * m > x) {
                high = m - 1;
            } else {
                low = m + 1;
            }
        }
        return -1;
    }
};