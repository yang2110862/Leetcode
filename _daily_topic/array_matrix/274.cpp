#include "header.h"
//H指数
class Solution {
private:
    unordered_map<int, int> mp;
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size() - 1;
        int h = 0;
        while (citations[n] > h) {
            ++h;
            --n;
        }
        return h;
    }
};