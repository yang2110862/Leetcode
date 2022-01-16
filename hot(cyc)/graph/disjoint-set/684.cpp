#include "header.h"

class Solution {
private:
    vector<int> parent;
    int find(int node) {
        if (parent[node] != node) parent[node] = find(parent[node]);
        return parent[node];
    }
    void join(int node1, int node2) {
        parent[find(node1)] = parent[node2];
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        for (int i = 1; i <= n; ++i) parent[i] = i;

        for (auto& edge : edges) {
            if(find(edge[0]) != find(edge[1])) {
                join(edge[0], edge[1]);
            } else {
                return edge;
            }
        }
        return {};
    }
};