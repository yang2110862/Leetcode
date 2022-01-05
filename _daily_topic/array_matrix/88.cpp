#include "header.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1;
        int index = (m + n) - 1;
        for (int i = index; i >= 0; --i) {
            if (p1 == -1) nums1[i] = nums2[p2--];
            else if (p2 == -1) nums1[i] = nums1[p1--];
            else nums1[i] = nums1[p1] >= nums2[p2] ? nums1[p1--] : nums2[p2--];
        }
    }
};

int main() {
    Solution test;
    vector<int> nums1{1,2,3,0,0,0}, nums2{2,5,6};
    test.merge(nums1,3,nums2,3);
}