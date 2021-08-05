#include "header.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> d(n);
        d[0] = nums[0];
        int len = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > d[len]) {
                d[++len] = nums[i];
            } else {
                int left = 0, right = len;
                while (left <= right) {
                    int mid = (left + right) >> 1;
                    if (d[mid] < nums[i]) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                if (right + 1 <= len && d[right + 1] > nums[i]) {
                    d[right + 1] = nums[i];
                }
            }
        }
        return len + 1;
    }
};

int main() {
    Solution test;
    vector<int> nums{10,9,2,5,3,7,101,18};
    cout << test.lengthOfLIS(nums);
}