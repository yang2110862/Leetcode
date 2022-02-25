#include "header.h"

// 9. 回文数
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        if (x % 10 == 0) return false;
        long sum = 0;
        long target = x;
        while (x) {
            int num = x % 10;
            sum = sum * 10 + num;
            x = x / 10;
        }
        if (sum == target) return true;
        else return false;
    }
};
