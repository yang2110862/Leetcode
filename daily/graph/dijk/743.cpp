#include "header.h"
#include <climits>
//网络延迟时间
class Solution {
private:
    vector<int> dist_to;
    vector<vector<pair<int, int>>> edges;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        dist_to.resize(n);
        edges.resize(n);
        for (int i = 0; i < n; ++i) dist_to[i] = INT_MAX / 2;
        for (auto& time : times) {
            int beg = time[0] - 1;
            int end = time[1] - 1;
            int d = time[2];
            edges[beg].emplace_back(end, d);
        }
        dist_to[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, k-1);
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int d = p.first, x = p.second;
            if (p.first > dist_to[x]) continue;
            for (auto& edge : edges[x]) {
                int y = edge.first, d = dist_to[x] + edge.second;
                if (d < dist_to[y]) {
                    dist_to[y] = d;
                    pq.emplace(d, y);
                }
            }
        }
        int ans = *max_element(dist_to.begin(), dist_to.end());
        return ans == INT_MAX / 2 ? -1 : ans;
    }
};