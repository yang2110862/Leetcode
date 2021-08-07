#include "header.h"

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int time = n;
            int next = nums[i];
            if (nums[i] > 0) {
                int k = 1;
                int num = n;
                while (num--) {
                    next = (next + nums[i]) % n;
                    if (next == i && k > 1) return true;
                    if (nums[next] < 0) break;
                    ++k;
                }
            }
            if (nums[i] < 0) {
                int k = 1;
                int num = n;
                while (num--) {
                    next = (((next + nums[i]) % n) + n) % n;
                    if (next == i && k > 1) return true;
                    if (nums[next] > 0) break;
                }
            }
        }
        return false;
    }
};