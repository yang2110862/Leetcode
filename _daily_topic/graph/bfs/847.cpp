#include "header.h"
#include <climits>

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        queue<tuple<int, int, int>> q;//三元组 node_id status dist
        int n = graph.size();
        vector<vector<int>> visited(n, vector<int>(1 << n, false));//减枝
        for (int i = 0; i < n; ++i) {
            auto temp = make_tuple(i, 1 << i, 0);
            q.push(temp);
            visited[i][1 << i] = true;
        }       
        while (!q.empty()) {
            auto [id, status, dist] = q.front();
            q.pop();
            if (status == (1 << n) - 1) return dist;
            for (auto next : graph[id]) {
                int new_status = status | (1 << next);
                if (visited[next][new_status]) continue;
                q.emplace(next, new_status, dist + 1);
                visited[next][new_status] = true;
            }
        }
        return -1;
    }
};