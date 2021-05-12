#include "header.h"
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        sort(points.begin(), points.end(), [](const auto& u, const auto& v) {
            return u[1] < v[1];
        });
        int right = points[0][1];
        int num = points.size();
        int ans = 1;
        for (int i = 1; i < num; ++i) {
            if (points[i][0] <= right) {
                continue;
            } else {
                right = points[i][1];
                ++ans;
            }
        }
        return ans;
    }
};