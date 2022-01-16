#include "header.h"

class Solution {
private:
    static constexpr int UNCOLORED = 0;
    static constexpr int RED = 1;
    static constexpr int GREEN = 2;
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colored(n, 0);
        for (int i = 0; i < n; ++i) {
            if (colored[i] == UNCOLORED) {
                colored[i] = RED;
                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int size = q.size();
                    for (int j = 0; j < size; ++j) {
                        int loc = q.front();
                        q.pop();
                        int nextColor = colored[loc] == RED ? GREEN : RED;
                        for (int next : graph[loc]) {
                            if (colored[next] == UNCOLORED) {
                                colored[next] = nextColor;
                                q.push(next);
                            }
                            else {
                                if (colored[next] != nextColor) return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
int main() {
    Solution test;
    vector<vector<int>> graph{{1,2,3}, {0,2}, {0,1,3}, {0,2}};
    auto x = test.isBipartite(graph);
    cout << x;
}