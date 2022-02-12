#include "header.h"

//根据身高重建队列

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        int n = people.size();
        vector<vector<int>> ans(n);
        for (const auto& p : people) {
            int space = p[1] + 1;
            for (int i = 0; i < n; ++i) {
                if (ans[i].empty()) --space;
                if (space == 0) {
                    ans[i] = p;
                    break;
                }
            }
        }
        return ans;
    }
};