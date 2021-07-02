//雪糕最大数量

#include "header.h"

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int sum = 0;
        int cnt = 0;
        for (auto cost : costs) {
            sum += cost;
            if (coins >= sum) ++cnt;
            else break;
        }
        return cnt;
    }
};