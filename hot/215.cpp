#include "header.h"

//数组中的第K个最大元素

class Solution {
private:
    void adjust(vector<int>& nums, int index, int len) {
        int maxNum = nums[index];
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        if (left < len && nums[left] > maxNum) {
            maxNum = nums[left];
            swap(nums[left], nums[index]);
        }
        if (right < len && nums[right] > maxNum) {
            swap(nums[right], nums[index]);
        }
    }
    void heapify(vector<int>& nums, int len) {
        int index = len / 2 - 1;
        for (int i = index; i >= 0; --i) {
            adjust(nums, i, len);
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int tail = n - 1;
        heapify(nums, n--);
        for (int i = 1; i < k; ++i) {
            swap(nums[0], nums[tail--]);
            heapify(nums, n--);
        }
        return nums[0];
    }
};

int main() {
    Solution test;
    vector<int> nums{2, 1};
    int k = 1;
    cout << test.findKthLargest(nums, k);
}