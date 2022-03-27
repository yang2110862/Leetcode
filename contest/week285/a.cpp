#include "header.h"

class Solution {
private:
    unordered_set<int> st1;
    unordered_set<int> st2;
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        for (auto x : nums1) st1.insert(x);
        for (auto x : nums2) st2.insert(x);
        vector<vector<int>> ans(2, vector<int>());
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        if (!st2.count(nums1[0])) ans[0].push_back(nums1[0]);
        if (!st1.count(nums2[0])) ans[1].push_back(nums2[0]);
        for (int i = 1; i < nums1.size(); ++i) {
            if (nums1[i] == nums1[i - 1]) continue;
            if (st2.count(nums1[i])) continue;
            ans[0].push_back(nums1[i]);
        }    
        for (int i = 1; i < nums2.size(); ++i) {
            if (nums2[i] == nums2[i - 1]) continue;
            if (st1.count(nums1[i])) continue;
            ans[1].push_back(nums2[i]);
        } 
        return ans;         
    }
};

int main() {
    Solution test;
    vector<int> a1{1,2,3};
    vector<int> a2{2,4,6};
    auto x = test.findDifference(a1, a2);
}