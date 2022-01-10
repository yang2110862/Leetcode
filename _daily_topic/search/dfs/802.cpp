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
            bool flag = dfs(i, graph, visited);
            if (flag) {
                ans.push_back(i);
                can_reach.insert(i);
            }
            else cannot_reach.insert(i);
        }
        return ans;
    }
};

//拓扑排序
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rgraph(n);
        vector<int> inDegree(n);
        for (int x = 0; x < n; ++x) {
            for (int y : graph[x]) {
                rgraph[y].push_back(x);
            }
            inDegree[x] = graph[x].size();
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto y : rgraph[x]) {
                if (--inDegree[y] == 0) {
                    q.push(y);
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};