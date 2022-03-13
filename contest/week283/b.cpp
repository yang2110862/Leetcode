#include "header.h"

class Solution {
private:
    void compute(long long beg, long long end, int& k, long long& sum) {
        if (end <= (beg + 1)) return;
        int num = end - beg - 1;
        if (k > num) {
            k -= num;
            sum += (beg + end) * num / 2;
        } else {
            sum += (beg + 1 + beg + k) * k / 2;
            k = 0;
        }
    }
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); 
        long long ans = 0;
        int n = nums.size();
        compute(0, nums[0], k, ans);
        for (int i = 1; i < n; ++i) {
            int beg = nums[i - 1];
            int end = nums[i];
            if (k == 0) return ans;
            else {
                compute(beg, end, k, ans);
            }
        } 
        if (k != 0) {
            int beg = nums[n - 1];
            int end = nums[n - 1] + k + 1;
            compute(beg, end, k, ans);
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<int> nums{96,44,99,25,61,84,88,18,19,33,60,86,52,19,32,47,35,50,94,17,29,98,22,21,72,100,40,84};
    cout << test.minimalKSum(nums, 35);
}