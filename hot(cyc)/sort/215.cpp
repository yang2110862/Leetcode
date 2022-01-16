#include "header.h"
class Solution {
public:
    void adjust(vector<int>& nums, int i, int heapSize) {
        int left = i * 2 + 1, right = i * 2 + 2, largest = i;
        if (left < heapSize && nums[left] > nums[largest]) {
            largest = left;
        }
        if (right < heapSize && nums[right] > nums[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(nums[i], nums[largest]);
            adjust(nums, largest, heapSize);
        }
    }

    void buildMaxHeap(vector<int>& nums, int heapSize) {
        for (int i = heapSize / 2 - 1; i >= 0; --i) {
            adjust(nums, i, heapSize);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        int count = heapSize - k;
        for (int i = heapSize - 1; i > count; --i) {
            swap(nums[0], nums[i]);
            --heapSize;
            adjust(nums, 0, heapSize);
        }
        return nums[0];
    }
};