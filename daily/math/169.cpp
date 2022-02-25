#include "header.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int num = 0;
        for (auto x : nums) {
            if (x == candidate) {
                ++num;
            } else if (--num < 0) {
                candidate = x;
                num = 1;
            }
        }
        return candidate;
    }
};