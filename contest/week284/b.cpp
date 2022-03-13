#include "header.h"

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<bool>> f(n, vector<bool>(n));
        for (const auto& d : dig) {
            f[d[0]][d[1]] = true;
        }
        int cnt = 0;
        for (const auto& artifact : artifacts) {
            int r1 = artifact[0], c1 = artifact[1], r2 = artifact[2], c2 = artifact[3];
            bool flag = true;
            for (int i = r1; i <= r2; ++i) {
                for (int j = c1; j <= c2; ++j) {
                    if (f[i][j] == false) {
                        flag = false;
                    }
                }
            }
            if (flag) ++ cnt;
        }
        return cnt;
    }
};