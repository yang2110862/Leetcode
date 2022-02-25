#include "header.h"
#include <queue>
//矩阵中战斗力最弱的K行
//找最后第一个1，在111000中找最后一个1的二分  left <= right
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> infors;
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; ++i) {
            int left = 0, right = n - 1;
            while (left <= right) {
                int mid = (left + right) >> 1;
                if (mat[i][mid] == 0) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            infors.emplace_back(right + 1, i);
        }
        sort(infors.begin(), infors.end());
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(infors[i].second);
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<vector<int>> mat{{1,1}, {1,0}};
    int k = 1;
    auto x = test.kWeakestRows(mat, k);
}