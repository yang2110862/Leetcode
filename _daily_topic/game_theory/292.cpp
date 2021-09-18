#include "header.h"
// 292 Nim游戏
class Solution {
public:
    bool canWinNim(int n) {
        if (n % 4 == 0) return false;
        return true;
    }
};