#include "header.h"

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int k = flowerbed.size();
        int num = 0;
        if (k == 1 && flowerbed[0] == 0) {
            num = 1;
        }
        if (k >= 2 && flowerbed[0] == 0 && flowerbed[1] == 0) {
            num += 1;
            flowerbed[0] = 1;
        }
        for (int i = 1; i < k - 1; ++i) {
            if (flowerbed[i] == 0 && flowerbed[i - 1] ==0 && flowerbed[i + 1] == 0) {
                num += 1;
                flowerbed[i] = 1;
            }
        }
        if (k >= 2 && flowerbed[k - 1] == 0 && flowerbed[k - 2] == 0) {
            num += 1;
        }
        return num >= n;
    }
};