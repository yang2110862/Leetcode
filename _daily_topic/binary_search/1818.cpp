#include "header.h"
//二分查找两次     绝对差值和
class Solution {
private:
    static constexpr int mod = 1000000007;
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr(nums1);
        sort(arr.begin(), arr.end());
        int sum = 0, maxDiff = 0;
        int n = nums1.size();
        for (int i = 0; i < n; ++i) {
            int preDiff = abs(nums1[i] - nums2[i]);
            int j = lower_bound(arr.begin(), arr.end(), nums2[i]) - arr.begin();
            if (j < n) maxDiff = max(maxDiff, preDiff - (arr[j] - nums2[i]));
            if (j > 0) maxDiff = max(maxDiff, preDiff - (nums2[i] - arr[j - 1]));
            sum = (sum + preDiff) % mod;
        }
        sum = (sum - maxDiff + mod) % mod;
        return sum;
    }
};