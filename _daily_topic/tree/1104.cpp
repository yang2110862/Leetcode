#include "header.h"
// 二叉树寻路
class Solution {
private:
    int getRow(int label) {
        int row = 1, rowStart = 1;
        while (rowStart * 2 <= label) {
            ++row;
            rowStart *= 2;
        }
        return row;
    }
    int getReverse(int label, int row) {
        return (1 << row - 1) + (1 << row) - 1 - label;
    }
public:
    vector<int> pathInZigZagTree(int label) {
        int row = getRow(label);
        if (row & 1 != 0) {
            label = getReverse(label, row);
        }
        vector<int> ans;
        while (row > 0) {
            if (row & 1 != 0) ans.push_back(getReverse(label, row));
            else ans.push_back(label);
            --row;
            label >>= 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};