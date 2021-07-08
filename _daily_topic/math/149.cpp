#include "header.h"

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            unordered_map<double, int> slopes;
            for (int j = 0; j < n; ++j) {
                if (j == i) continue;
                int x2 = points[j][0];
                int y2 = points[j][1];
                double slope = 1.0 * (y2 - y1) / (x2 - x1);
                slopes[slope]++;
                ans = max(ans, slopes[slope] + 1);
            }
        }
        return ans;
    }
};