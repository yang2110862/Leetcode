#include "header.h"

//和为 K 的子数组
//WA
class Solution1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int p1 = 0, p2 = 0;
        int sum = nums[0];
        int ans = 0;
        while (p1 < n && p2 < n) {
            if (sum == k) {
                ++ans;
                sum -= nums[p1];
                p1++;
            } else if (sum < k) {
                ++p2;
                if (p2 < n) {
                    sum += nums[p2];
                }
            } else {
                sum -= nums[p1];
                ++p1;
            }
        }
        return ans;
    }
};

//前缀和

class Solution {
private:
    unordered_map<int, int> cnt;
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        cnt[0] = 1;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (cnt.count(sum - k)) {
                ans += cnt[sum - k];
            }
            cnt[sum]++;
        }
        return ans;
    }
};