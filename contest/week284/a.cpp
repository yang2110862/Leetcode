#include "header.h"

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int delta = 0;
            bool flag = true;
            while (flag) {
                if (i - delta >= 0 && nums[i - delta] == key) {
                    if (delta <= k) {
                        ans.push_back(i);
                    }
                    break;
                } else if (i + delta < n && nums[i + delta] == key) {
                    if (delta <= k) {
                        ans.push_back(i);
                    }
                    break;
                }
                ++delta;
            }
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<int> nums{3,4,9,1,3,9,5};
    auto x = test.findKDistantIndices(nums, 9 , 1);
    return 0;
}