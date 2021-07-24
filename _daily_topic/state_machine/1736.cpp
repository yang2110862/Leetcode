#include "header.h"
//替换隐藏数字得到的最晚时间，非状态机实现
class Solution {
public:
    string maximumTime(string time) {
        if (time[0] == '?') {
            time[0] = ('4' <= time[1] && time[1] <= '9') ? '1' : '2';
        }
        if (time[1] == '?') {
            time[1] = (time[0] == '2') ? '3' : '9';
        }
        if (time[3] == '?') {
            time[3] = '5';
        }
        if (time[4] == '?') {
            time[4] = '9';
        }
        return time;
    }
};
