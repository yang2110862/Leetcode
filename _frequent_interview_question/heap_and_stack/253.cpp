#include "header.h"

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto interval : intervals) {
            if (!q.empty() && interval[0] >= q.top()) {
                q.pop();
            }
            q.push(interval[1]);
        }
        return q.size();
    }
};