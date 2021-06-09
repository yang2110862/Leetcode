#include "header.h"

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (auto num : stones) sum += num;
        int n = stones.size();
        int new_target = sum / 2;
        vector<int> dp(new_target + 1); 
        dp[0] = 0;
        for (auto num : stones) {
            for (int i = new_target; i >= num; --i) {
                dp[i] = max(dp[i], dp[i - num] + num);
            }
        }
        return sum - 2 * dp[new_target];
    }
};