#include "header.h"

int rand7();
class Solution {
public:
    int rand10() {
        int row = rand7();
        int col = rand7();
        int num = 7 * (row - 1) + col;
        while (num > 40) {
            row = rand7();
            col = rand7();
            num = 7 * (row - 1) + col;
        }
        return (num - 1) / 4 + 1;
    }
};