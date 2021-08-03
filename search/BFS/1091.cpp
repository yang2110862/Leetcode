#include "header.h"
struct Node {
    int x;
    int y;
};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<Node> q;
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) {
            return -1;
        }
        vector<vector<int>> mem(m, vector<int>(n , 0));    //初始化也可以用容器
        mem[0][0] = 1;
        q.push({0, 0});
        int ans = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i){
                auto curr = q.front();
                if (curr.x == (n - 1) && curr.y == (m - 1)) {
                    return ans + 1;
                }
                int x = curr.x;
                int y = curr.y;
                vector<Node> nextNodes{{x + 1, y}, {x - 1, y}, {x + 1, y + 1}, {x - 1, y - 1},
                                        {x, y + 1}, {x, y - 1}, {x + 1, y - 1}, {x - 1, y + 1}};
                for (auto& k : nextNodes) {
                    if (k.x < 0 || k.x >= n || k.y < 0 || k.y >= m || mem[k.y][k.x] ==1 || grid[k.y][k.x] == 1) {
                        continue;
                    }
                    mem[k.y][k.x] = 1;
                    q.push(k);
                }
                q.pop();
            }
            ++ans;
        }
        return -1;
    }
};
