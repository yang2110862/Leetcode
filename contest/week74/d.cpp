#include "header.h"

class Solution {
private:
    int cumputer(string& floor, int index, int carpetLen) {
        int cnt = 0;
        while (carpetLen--) {
            if (floor[index++] == '1') {
                ++cnt;
            }
        }
        return cnt;
    }
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int m = floor.size();
        if (numCarpets * carpetLen >= m) return 0;
        for (int i = 0; i < numCarpets; ++i) {
            int index = 0;
            int maxNum = 0;
            int t = carpetLen;
            for (int j = 0; j < m - carpetLen + 1; ++j) {
                int cnt = cumputer(floor, j, carpetLen);
                if (cnt > maxNum) {
                    maxNum = cnt;
                    index = j;
                }
            }
            while (t--) {
                floor[index++] = '0';
            }
        }  
        int ans = 0;
        for (auto c : floor) {
            if (c == '1') ++ans;
        }
        return ans;
    }
};