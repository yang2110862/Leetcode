#include "header.h"
//最长连续序列

class Solution1 {
private:
unordered_set<int> st;
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            st.insert(nums[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (st.count(nums[i] - 1)) continue;
            int cnt = 1;
            int num = nums[i] + 1;
            while (st.count(num)) {
                ++num;
                ++cnt;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};