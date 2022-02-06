#include "header.h"

//戳气球

//TTL
class Solution {
private:
    int n;
    int ans;
    void backtrace(const vector<int>& nums, vector<int>& visited, int cnt, int sum) {
        if (cnt == n) {
            ans = max(ans, sum);
        }
        for (int i = 0; i < n; ++i) {
            if (visited[i] == 1) continue;
            visited[i] = 1;
            int left = i;
            int right = i;
            while (left >= 0 && visited[left]) {
                --left;
            }
            while (right < n && visited[right]) {
                ++right;
            }
            int temp = nums[i];
            temp *= left >= 0 ? nums[left] : 1;
            temp *= right < n ? nums[right] : 1;
            backtrace(nums, visited, cnt + 1, sum + temp);
            visited[i] = 0;
        }
    }
public:
    int maxCoins(vector<int>& nums) {
        n = nums.size();
        ans = 0;
        vector<int> visited(n, 0);
        backtrace(nums, visited, 0, 0);
        return ans;
    }
};