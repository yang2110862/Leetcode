#include "header.h"

//堆排
class Solution {
private:
    void maxHeapify(vector<int>& nums, int i, int heapSize) {
        int left = 2 * i + 1, right = 2 * i + 2, largest = i;
        if (left < heapSize && nums[left] > nums[largest]) {   //跟nums[largest]比   如果跟nums[i]比要比两次必要浪费时间
            largest = left;
        }
        if (right < heapSize && nums[right] > nums[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(nums[i], nums[largest]);
            maxHeapify(nums, largest, heapSize);
        }
    }   
    void buildMaxHeap(vector<int>& nums, int heapSize) {
        for (int i = heapSize / 2 - 1; i >= 0; --i) {
            maxHeapify(nums, i, heapSize);
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        for (int i = 0; i < k - 1; ++i) {
            swap(nums[0], nums[heapSize - 1]);
            heapSize--;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
};