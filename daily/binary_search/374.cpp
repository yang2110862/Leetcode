#include "header.h"

int guess(int num);
class Solution {
public:
    int guessNumber(int n) {
        long long left = 1, right = n;
        while (left <= right) { 
            int mid = (left + right) >> 1;
            int jug = guess(mid);
            if (jug == 0) return mid;
            else if (jug == -1) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};