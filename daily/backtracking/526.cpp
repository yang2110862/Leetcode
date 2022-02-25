#include "header.h"
//优美的排列

class Solution {
private:
    int ans;
    void backtrack(int index, int n, vector<bool> visited) {
        if (index == n + 1) {
            ++ans;
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if (visited[i]) continue;
            if (i % index == 0 || index % i == 0) {
                visited[i] = true;
                backtrack(index + 1, n, visited);
                visited[i] = false;
            }
        }
    }
public:
    int countArrangement(int n) {
        vector<bool> visited(n + 1, false);
        backtrack(1, n, visited);
        return ans;
    }
};

