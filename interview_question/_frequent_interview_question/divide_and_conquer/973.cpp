#include "header.h"

//分治算法-快排
class Solution {
private:
    inline int partition(vector<vector<int>>& points, int left, int right) {
        int x = points[right][0] * points[right][0] + points[right][1] * points[right][1];
        int i = left - 1;
        for (int j = left; j < right; ++j) {
            int y = points[j][0] * points[j][0] + points[j][1] * points[j][1];
            if (y < x) {
                swap(points[j], points[++i]);
            }
        }
        swap(points[right], points[i + 1]);
        return i + 1;
    }
    inline int randomPartition(vector<vector<int>>& points, int left, int right) {
        int i = rand() % (right - left + 1) + left;
        swap(points[i], points[right]);
        return partition(points, left, right);
    }
    void quickSort(vector<vector<int>>& points, int left, int right) {
        if (left >= right) return;
        int k = randomPartition(points, left, right);
        quickSort(points, left, k - 1);
        quickSort(points, k + 1, right);
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        srand(time(0));
        quickSort(points, 0, points.size() - 1);
        vector<vector<int>> ans(points.begin(), points.begin() + k);
        return ans;
    }
};
