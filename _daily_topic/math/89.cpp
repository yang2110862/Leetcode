#include "header.h"

//89. 格雷编码
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        ret.push_back(0);
        for (int i = 1; i <= n; i++) {
            int m = ret.size();
            for (int j = m - 1; j >= 0; j--) {
                ret.push_back(ret[j] | (1 << (i - 1)));
            }
        }
        return ret;
    }
};
