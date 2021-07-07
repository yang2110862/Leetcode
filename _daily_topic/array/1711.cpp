#include "header.h"
//大餐计数  hash+数组
class Solution {
private:
    static constexpr int mod = 1000000007;
    unordered_map<int, int> mp;
public:
    int countPairs(vector<int>& deliciousness) {
        int max_val = *max_element(deliciousness.begin(), deliciousness.end());
        int max_sum = max_val * 2;
        int ans = 0;
        for (auto x : deliciousness) {
            for (int sum = 1; sum <= max_sum; sum <<= 1) {
                int count = mp.count(sum - x) ? mp[sum - x] : 0;
                ans = (ans + count) % mod;
            }
            ++mp[x];
        }
        return ans;
    }
};