#include "header.h"

//寻找两个正序数组的中位数

class Solution {
private:
    vector<int> merge(const vector<int>& nums1, const vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> ans;
        ans.reserve(m + n);
        int p1 = 0, p2 = 0;
        for (int i = 0; i < n + m; ++i) {
            int num1 = p1 == m ? INT_MAX : nums1[p1];
            int num2 = p2 == n ? INT_MAX : nums2[p2];
            if (num1 < num2) {
                ans.push_back(num1);
                ++p1;
            } else {
                ans.push_back(num2);
                ++p2;
            }
        }
        return ans;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v = merge(nums1, nums2);
        int n = v.size();
        if (n & 1) {
            return v[n / 2];
        } else {
            double mid = 1.0 * (v[n / 2] + v[n / 2 - 1]) / 2;
            return mid;
        }
        return 0;
    }
};

int main() {
    vector<int> num1{1,2};
    vector<int> num2{3,4};
    Solution test;
    auto x = test.findMedianSortedArrays(num1, num2);
}