#include "header.h"
//暴力法
class Solution1 {
private:
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> ans;
        int p1 = 0, p2 = 0;
        while (p1 < m || p2 < n) {
            if (p1 == m) {
                for (int i = p2; i < n; ++i) {
                    ans.push_back(nums2[i]);
                }
                break;
            }
            if (p2 == n) {
                for (int i = p1; i < m; ++i) {
                    ans.push_back(nums1[i]);
                }
                break;
            }
            if (nums1[p1] < nums2[p2]) {
                ans.push_back(nums1[p1++]);
            } else {
                ans.push_back(nums2[p2++]);
            }
        }
        return ans;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> newArr = merge(nums1, nums2);
        int n = newArr.size();
        if (n & 1) {
            return newArr[n >> 1];
        } else {
            return 1.0 * (newArr[n >> 1] + newArr[(n >> 1) - 1]) / 2;
        }
    }
};

//二分

class Solution {
private:
    int getKthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        int low1 = 0, low2 = 0;
        while (true) {
            if (low1 == m) {
                return nums2[low2 + k - 1];
            }
            if (low2 == n) {
                return nums1[low1 + k - 1];
            }
            if (k == 1) return min(nums1[low1], nums2[low2]);
            int newLow1 = min(low1 + k / 2 - 1, m - 1);
            int newLow2 = min(low2 + k / 2 - 1, n - 1);
            if (nums1[newLow1] < nums2[newLow2]) {
                k -= newLow1 - low1 + 1;
                low1 = newLow1 + 1;
            } else {
                k -= newLow2 - low2 + 1;
                low2 = newLow2 + 1;
            }
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = nums1.size() + nums2.size();
        if (sum & 1) {
            return getKthElement(nums1, nums2, (sum + 1) / 2);
        } else {
            cout << getKthElement(nums1, nums2, sum / 2);
            cout << ' ' << getKthElement(nums1, nums2, sum / 2 + 1);
            return 1.0 * (getKthElement(nums1, nums2, sum / 2) + getKthElement(nums1, nums2, sum / 2 + 1)) / 2;
        }
    }
};

int main() {
    Solution test;
    vector<int> nums1{1,2};
    vector<int> nums2{3, 4};
    cout << test.findMedianSortedArrays(nums1, nums2);
}