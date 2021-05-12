#include "header.h"
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const auto& u, const auto& v) {
            return u[0] < v [0] || (u[0] == v[0] && u[1] > v[1]);
        });
        int n = people.size();
        vector<vector<int>> ans(n);
        int spaces;
        for (auto x : people) {
            spaces = x[1] + 1;              //学习怎么在数组中间跳过一部分再插入
            for (int j = 0; j < n; ++j) {
                if (ans[j].empty()) {             
                    --spaces;
                    if (!spaces) {
                        ans[j] = x;
                    }
                }

            }
        }
        return ans;
    }
};