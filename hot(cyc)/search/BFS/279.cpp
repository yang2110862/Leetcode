#include "header.h"

class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i * i <= n; ++i) {
            squares.emplace_back(i * i);   //一会试试push back
        }
        queue<int> q;
        q.push(n);
        int ans = 0;
        //开始bfs
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front();
                for (auto x : squares) {
                    if (curr - x < 0) {
                        break;
                    } else if (curr - x == 0) {
                        return ans + 1;
                    } else {
                        q.push(curr - x);
                    }
                }
                q.pop();
            }
            ++ans;
        }
        return ans;
    }
};