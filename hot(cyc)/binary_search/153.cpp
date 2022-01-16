#include "header.h"

class Solution1 {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n - 2;
        while (low <= high) {
            int m = low + (high - low) / 2;
            if (nums[m] < nums[m - 1] && nums[m] < nums[m + 1]) {
                return nums[m];
            } else if (nums[m] > nums[0]) {
                low = m + 1;
            } else {
                high = m - 1;
            }
        }
        return min(nums[0], nums[n - 1]);
    }
};
//找到第一个比nums[n - 1] 小的
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int left = 0, right = nums.size() - 2;
        while (left <= right) {
            int mid = (left + right) >> 1;  
            if (nums[mid] > nums[n - 1]) {
                left = mid + 1;
            } else if(nums[mid] < nums[n - 1]) {
                right = mid - 1;
            }
        }
        return nums[left];
    }
};

//更像二分的形式，没有剔除掉最后一个元素
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;    
            }
        }
        return nums[right];
    }
};