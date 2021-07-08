#include "header.h"

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<long long> pre(n);
        pre[0] = candiesCount[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i - 1] + candiesCount[i];
        }
        int m = queries.size();
        vector<bool> ans(m);
        for (int i = 0; i < m; ++i) {
            int type = queries[i][0];
            int day = queries[i][1];
            int cap = queries[i][2];
            bool low = false;
            bool high = false;
            long long eat_max = (long long)cap * (day + 1);
            if (eat_max >= (pre[type] - candiesCount[type] + 1)) high = true;
            long long eat_min = day + 1;
            if (eat_min <= pre[type]) low = true;
            if (high && low) ans[i] = true;
        }
        return ans;
    }
};