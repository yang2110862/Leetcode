#include "header.h"

bool isBadVersion(int n);
class Solution {
public:
    int firstBadVersion(int n) {
        long long left = 1, right = n;
        while (left < right) { 
            long long mid = (left + right) >> 1; 
            if (isBadVersion(mid)) {
                right = mid; 
            } else {
                left = mid + 1; 
            }
        }
        return left;
    }
};
