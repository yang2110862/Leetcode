#include "header.h"
//也可以两个dp[i]  分别表示最后摇摆向上还是向下，会快点。  
//多学学分情况
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 1;
        }
        vector<int> dp(n, 1);  //dp[i]表示[0,i]中最长子序列的长度
        vector<int> flag(n, 1); //dp[i]最长子序列当前是正（1表示）还是负0, -1表示第一个
        flag[0] = -1;
        int ans = 1;
        if (nums[1] > nums[0]) {
            flag[1] = 1;
        } else if (nums[1] < nums[0]){
            flag[1] = 0;
        } else {
            flag[1] = -1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (flag[j] == 1) {
                    if (nums[i] < nums[j]) {
                        dp[i] = max(dp[i], dp[j] + 1);
                        flag[i] = false;
                    }
                } else if (flag[j] == 0) {
                    if (nums[i] > nums[j]) {
                        dp[i] = max(dp[i], dp[j] + 1);
                        flag[i] = true;
                    }
                } else {
                    if (nums[i] == nums[j]) {
                        dp[i] = dp[j];
                        flag[i] = -1;
                    } else {
                        dp[i] = 2;
                        if (nums[i] > nums[j]) {
                            flag[i] = 1;
                        } else {
                            flag[i] = 0;
                        }
                    }
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<int> arr{3, 3,3,2,5};
    cout << test.wiggleMaxLength(arr);
}