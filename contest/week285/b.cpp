#include "header.h"

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int pre;
        int ans = 0;
        int index = 0;
        for (auto x : nums) {
            if (index % 2 == 1 && x == pre) {
                ++ans;
            } else {
                ++index;
                pre = x;
            }
        }
        if (index % 2 == 0) ++ans;
        return ans;
    }
};