#include "header.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int beg = -1, end = -1;
        while (low <= high){
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                beg = end = mid;
                while ((--mid >= 0) && nums[mid] == target) {
                    --beg;
                    --end;
                }
                while ((++mid <= n-1) && nums[mid] == target) {
                    ++end;
                }
                break;  //问题解决后一定要跳出while，不然陷进去死循环
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            
        }
        vector<int> ans;
        if (end != -1) {
            --end;
        }
        ans.push_back(beg);
        ans.push_back(end);
        return ans;
    }
};