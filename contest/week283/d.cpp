#include "header.h"

class Solution {
private:
    long long gcd(long long a,long long b) {
        long long r;
        while(b>0) {
            r=a%b;
            a=b;
            b=r;
        }
        return a;
    }
    long long lcm(long long a, long long b) {
        return a * b / gcd(a, b);
    }
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;;
        long long n = nums.size();
        long long last = nums[0];
        for (long long i = 1; i < n; ++i) {
            if (gcd(last, nums[i]) > 1) {
                last = lcm(last, nums[i]);
            } else {
                ans.push_back(last);
                last = nums[i];
            }
        }
        ans.push_back(last);
        return ans;
    }
};

class Solution1 {
public:
    int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
    
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int t = nums[i];
            while (!ans.empty() && gcd(t, ans.back()) > 1) {
                t = t / gcd(t, ans.back()) * ans.back();
                ans.pop_back();
            }
            ans.push_back(t);
        }
        return ans;
    }
};

int main() {
    Solution1 test;
    vector<int> nums{287,41,49,287,899,23,23,20677,5,825};
    auto x = test.replaceNonCoprimes(nums);
    return 0;
}