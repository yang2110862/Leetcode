#include "header.h"

class Solution {
private:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> map;
        map[0] = 1;
        int pre = 0;
        int cnt = 0;
        for (auto num : nums) {
            pre += num;
            if (map.find(pre - k) != map.end()) {
                cnt += map[pre - k];
            }
            ++map[pre];
        }
        return cnt;
    }
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            vector<int> pre(n);
            for (int j = i; j < m; ++j) {
                for (int k = 0; k < n; ++k) {
                    pre[k] += matrix[j][k];
                }
                ans += subarraySum(pre, target);
            }
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<vector<int>> matrix{{0,1,0}, {1,1,1}, {0,1,0}};
    int target = 0;
    cout << test.numSubmatrixSumTarget(matrix, target);
    return 0;
}