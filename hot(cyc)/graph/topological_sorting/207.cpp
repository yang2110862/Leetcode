#include "header.h"

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    vector<int> result;
    bool valid = true;
    void dfs(int u) {
        visited[u] = 1;
        for (int i : edges[u]) {
            if (visited[i] == 1) {
                valid = false;
                return;
            } else if (visited[i] == 0) {
                dfs(i);
                if (!valid) return;
            }
        }
        visited[u] = 2;
        result.push_back(u);
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& arr : prerequisites) {
            edges[arr[1]].push_back(arr[0]);
        }
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        if (!valid) return false;
        return true;
    }
};