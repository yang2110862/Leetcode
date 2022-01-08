#include "header.h"


//215. 数组中的第K个最大元素   堆排序
class Solution {
private:
    void maxHeapify(vector<int>& nums, int i, int len) {
        int l = i * 2 + 1, r = i * 2 + 2;
        int largest = i;
        if (l < len && nums[l] > nums[largest]) {
            largest = l;
        }
        if (r < len && nums[r] > nums[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(nums[i], nums[largest]);
            maxHeapify(nums, largest, len);
        }
    }
    void bulidHeap(vector<int>& nums) {
        int n = nums.size();
        int beg = n / 2 - 1;
        for (int i = beg; i >= 0; --i) {
            maxHeapify(nums, i, n);
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        bulidHeap(nums);
        int n = nums.size();
        for (int i = 0; i < k - 1; ++i) {
            swap(nums[0], nums[n - 1]);
            --n;
            maxHeapify(nums, 0, n);
        }
        return nums[0];
    }
};