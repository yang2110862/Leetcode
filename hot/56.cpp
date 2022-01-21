#include "header.h"

//合并区间

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int n = intervals.size();
        int l = intervals[0][0], r = intervals[0][1];
        vector<vector<int>> ans;
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] <= r) {
                r = max(intervals[i][1], r);
            } else {
                ans.push_back({l, r});
                l = intervals[i][0];
                r = intervals[i][1];
            }
        }
        ans.push_back({l, r});
        return ans;
    }
};