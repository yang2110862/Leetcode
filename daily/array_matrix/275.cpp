#include "header.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size() - 1;
        int h = 0;
        while (n >= 0 && citations[n] > h) {
            ++h;
            --n;
        }
        return h;
    }
};