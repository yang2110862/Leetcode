#include "header.h"

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);      //-1为着色，0，1代表两种不同颜色
        stack<int> color_stack;
        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                color_stack.push(i);
                color[i] = 0;
            }
            while (!color_stack.empty()) {
                int index = color_stack.top();
                color_stack.pop();
                for (int j = 0; j < graph[index].size(); ++j) {
                    if (color[graph[index][j]] == -1) {
                        color[graph[index][j]] = color[index] ^ 1;
                        color_stack.push(graph[index][j]);
                    } else {
                        if (color[graph[index][j]] != color[index] ^ 1) return false;
                    }
                }
            }
        }
        return true;
    }
};