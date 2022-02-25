#include "header.h"

//消除游戏   
//只需要记录数组里第一个元素即可,非必要信息和内容不需要记录
class Solution {
public:
    int lastRemaining(int n) {
        int a1 = 1, an = n;
        int step = 1; //当前序列邻近元素的差值
        int cnt = 1;
        while (n > 1) {
            if (cnt & 1) {
                if (n & 1) {
                    a1 += step;
                    an -= step;
                } else {
                    a1 += step;
                }
            } else {
                if (n & 1) {
                    a1 += step;
                    an -= step;
                } else {
                    an -= step;
                }
            }
            n >>= 1;
            step <<= 1;
            cnt++;
        }
        return a1;
    }
};