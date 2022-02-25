#include "header.h"

class Solution {
private:
    static constexpr int mod = 1000000000 + 7;
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        long ans = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(startRow, startColumn));
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (maxMove--) {
            int num = q.size();
            int new_row, new_column;
            for (int i = 0; i < num; ++i) {
                auto temp = q.front();
                q.pop();
                for (auto& dir : dirs) {
                    new_row = temp.first + dir[0];
                    new_column = temp.second + dir[1];
                    if (new_row < 0 || new_row >= m || new_column < 0 || new_column >=n) {
                        ans = (ans + 1) % mod;
                    } else {
                        q.push(make_pair(new_row, new_column));
                    }
                }
            }
        }
        return ans;
    }
};