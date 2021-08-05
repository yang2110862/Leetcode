#include "header.h"

class Solution {
private:
    set<int> cannot_reach;
    set<int> can_reach;
    bool dfs(int index, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[index] = true;
        for (int next : graph[index]) {
            if (cannot_reach.count(next)) return false;
            if (can_reach.count(next)) continue;
            if (visited[next]) return false;
            else {
                if (dfs(next, graph, visited)) {
                    can_reach.insert(next);
                    continue;
                }
                else {
                    cannot_reach.insert(next);
                    return false;
                }
            }
        }
        visited[index] = false;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (cannot_reach.count(i)) continue;
            if (can_reach.count(i)) {
                ans.push_back(i);
                continue;
            }
            vector<bool> visited(n, false);
            bool can_reach = dfs(i, graph, visited);
            if (can_reach) {
                ans.push_back(i);
                can_reach
            }
            else cannot_reach.insert(i);
        }
        return ans;
    }
};