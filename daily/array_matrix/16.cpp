#include "header.h"
#include <climits>
//  最接近的三数之和

// 双循环+二分， 128/133  不debug了 也不常规这方法
class Solution1 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = INT_MAX >> 2;
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                int sum = nums[i] + nums[j];
                if (sum >= target) {
                    sum += nums[j + 1];
                    if (abs(sum - target) < abs(target - ans)) {
                        ans = sum;
                    }
                } else {
                    int tar = target - sum;
                    int l = j + 1, r = n - 1;
                    if (nums[l] >= tar) {
                        sum += nums[l];
                        if (abs(sum - target) < abs(target - ans)) {
                            ans = sum;
                        }  
                        continue; 
                    }
                    while (l < r) {
                        int mid = (l + r) >> 1;
                        if (nums[mid] >= tar) {
                            r = mid;
                        } else {
                            l = mid + 1;
                        }
                    }
                    sum += nums[l];
                    if (abs(sum - target) < abs(target - ans)) {
                        ans = sum;
                    } 
                    sum -= nums[l];
                    if (l - 1 != j) {
                        sum += nums[l - 1];
                        if (abs(sum - target) < abs(target - ans)) {
                            ans = sum;
                        } 
                    } 
                }
            }
        }
        return ans;
    }
};

//排序 + 双指针

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = INT_MAX >> 1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            int tar = target - nums[i];
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[l] + nums[r] + nums[i];
                if (abs(sum - target) < abs(ans - target)) {
                    ans = sum;
                }
                int num = nums[l] + nums[r];
                if (num >= tar) {
                    --r;
                } else {
                    ++l;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<int> arr{0,2,1,-3};
    int tar = 1;
    cout << test.threeSumClosest(arr, tar);
}