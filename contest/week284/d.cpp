#include "header.h"

class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, int>>> G(n), Grev(n);
        for (auto const& edge : edges) {
            int x = edge[0], y = edge[1], dis = edge[2];
            G[x].emplace_back(y, dis);
            Grev[y].emplace_back(x, dis);
        }
        auto dijkstra = [&n](const vector<vector<pair<int, int>>>& graph, int beg) -> vector<long long> {
            vector<long long> dist(n, -1);
            dist[beg] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
            vector<bool> visited(n);
            q.emplace(beg, 0);
            while (!q.empty()) {
                int u = q.top().first;
                q.pop();
                if (visited[u]) continue;
                visited[u] = true;
                for (const auto& p : graph[u]) {
                    int v = p.first, weight = p.second;
                    long long target = dist[u] + weight;
                    if (dist[v] == -1 || dist[v] > target) {
                        dist[v] = target;
                        q.emplace(v, dist[v]);
                    }
                }
            }
            return dist;
        };
        auto d1 = dijkstra(G, src1);
        auto d2 = dijkstra(G, src2);
        auto d3 = dijkstra(Grev, dest);
        long ans = -1;
        for (int i = 0; i < n; ++i) {
            if (d1[i] != -1 && d2[i] != -1 && d3[i] != -1) {
                long res = d1[i] + d2[i] + d3[i];
                if (ans == -1 || res < ans) {
                    ans = res;
                }
            }
        }
        return ans;
    }
};