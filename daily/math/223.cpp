#include "header.h"

//223. 矩形面积

class Solution1 {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int width = 0, height = 0;
        if (ax1 < bx1) {
            if (bx1 < ax2) {
                if (bx2 > ax2) width = ax2 - bx1;
                else width = bx2 - bx1;
            }
        } else {
            if (ax1 < bx2) {
                if (ax2 > bx2) width = bx2 - ax1;
                else width = ax2 - ax1;
            }
        }
        if (ay1 < by1) {
            if (by1 < ay2) {
                if (by2 > ay2) height = ay2 - by1;
                else height = by2 - by1;
            }
        } else {
            if (ay1 < by2) {
                if (ay2 > by2) height = by2 - ay1;
                else height = ay2 - ay1;
            }
        }
        return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - width * height;
    }
};

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2 - ax1) * (ay2 - ay1), area2 = (bx2 - bx1) * (by2 - by1);
        int overlapWidth = min(ax2, bx2) - max(ax1, bx1), overlapHeight = min(ay2, by2) - max(ay1, by1);
        int overlapArea = max(overlapWidth, 0) * max(overlapHeight, 0);
        return area1 + area2 - overlapArea;
    }
};
