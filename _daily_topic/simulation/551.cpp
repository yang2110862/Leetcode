#include "header.h"

class Solution {
public:
    bool checkRecord(string s) {
        int A_num = 0;
        int continous_L = 0;
        for (auto c : s) {
            if (c == 'A') {
                A_num++;
                if (A_num == 2) return false;
            }
            if (c == 'L') {
                continous_L++;
                if (continous_L == 3) return false;
            } else {
                continous_L = 0;
            }
        }
        return true;
    }
};