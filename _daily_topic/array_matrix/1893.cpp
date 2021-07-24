#include "header.h"
//检查是否区域内所有整数都被覆盖  差分数组

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff(52, 0);
        for (auto& range : ranges) {
            ++diff[range[0]];
            --diff[range[1] + 1];
        }
        int curr = 0;
        for (int i = 1; i <= right; ++i) {
            curr += diff[i];
            if (i >= left && curr <= 0) return false;
        }
        return true;
    }
};


