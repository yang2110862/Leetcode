#include "header.h"

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int time = n;
            int next = i;
            if (nums[i] > 0) {
                int k = 1;
                int num = n;
                while (num--) {
                    next = (((next + nums[next]) % n) + n) % n;
                    if (next == i && k > 1) return true;
                    if (next == i && k == 1) break;
                    if (nums[next] < 0) break;
                    ++k;
                }
            }
            if (nums[i] < 0) {
                int k = 1;
                int num = n;
                while (num--) {
                    next = (((next + nums[next]) % n) + n) % n;
                    if (next == i && k > 1) return true;
                    if (next == i && k == 1) break;
                    if (nums[next] > 0) break;
                    ++k;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution test;
    vector<int> nums{-1, -1};
    cout << test.circularArrayLoop(nums);
}