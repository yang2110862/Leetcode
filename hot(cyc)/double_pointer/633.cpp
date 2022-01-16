#include "header.h"
class Solution {
public:
    bool judgeSquareSum(int c) {
        int high = sqrt(c);
        int low = 0;
        while (low <= high) {
            unsigned int sum = pow(high, 2) + pow(low, 2);
            if(sum == c) {
                return true;
            } else if (sum > c) {
                high--;
            } else {
                low++;
            }
        }
        return false;
    }
};