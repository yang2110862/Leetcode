#include "header.h"

//暴力法
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    for (int l = k + 1; l < n; ++l) {
                        if (nums[l] == sum) ++ans;
                    }
                }
            }
        }
        return ans;
    }
};

//hash n^3  第三层循环逆序！！！！且放到第一层
class Solution {
private:
    unordered_map<int, int> cnt;
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return 0;
        int ans = 0;
        for (int k = n - 2; k >= 2; --k) {
            ++cnt[nums[k + 1]];
            for (int i = 0; i < k; ++i) {
                for (int j = i + 1; j < k; ++j) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (cnt.count(sum)) {
                        ans += cnt[sum];
                    }
                }
            }
        }
        return ans;
    }
};

//hash 0^2  a+b+c=d -> a+b=d-c

class Solution {
private:
    unordered_map<int, int>cnt;
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int j = n - 3; j >= 1; --j) {
            for (int d = j + 2; d < n; ++d) {
                ++cnt[nums[d] - nums[j + 1]];
            }
            for (int i = 0; i < j; ++i) {
                int sum = nums[j] + nums[i];
                if (cnt.count(sum)) {
                    ans += cnt[sum];
                }
            }
        }
        return ans;
    }
};

