#include "header.h"
class Solution1 {
private:
    static constexpr int UNCOLORED = 0;
    static constexpr int RED = 1;
    static constexpr int GREEN = 2;
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        for (int i = 0; i < n; ++i) {
            if (color[i] == UNCOLORED) {
                queue<int> q;
                q.push(i);
                color[i] = RED;
                while (!q.empty()) {
                    int node = q.front();
                    int cNei = (color[node] == RED ? GREEN : RED);
                    q.pop();
                    for (int neighbor: graph[node]) {
                        if (color[neighbor] == UNCOLORED) {
                            q.push(neighbor);
                            color[neighbor] = cNei;
                        }
                        else if (color[neighbor] != cNei) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    Solution1 test;
    vector<vector<int>> graph{{1,2,3}, {0,2}, {0,1,3}, {0,2}};
    auto x = test.isBipartite(graph);
    cout << "hehe";
}