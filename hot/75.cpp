#include "header.h"

//颜色分类
//从左边再换回来的一定不会是2，而从右边换回来的可能是0
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        for (int i = 0; i <= r; ++i) {
            while (nums[i] == 2 && i <= r) {
                swap(nums[i], nums[r--]);
            }
            if (nums[i] == 0) swap(nums[i], nums[l++]);
        }
    }
};
