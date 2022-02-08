#include "header.h"

//前 K 个高频元素

class Solution {
private:
    unordered_map<int, int> cnt;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            cnt[nums[i]]++;
        }
        vector<pair<int, int>> cnts;
        for (auto& it : cnt) {
            cnts.push_back(it);
        }
        sort(cnts.begin(), cnts.end(), [](const pair<int, int>& first, const pair<int, int>& second) {
            return first.second > second.second;
        });
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(cnts[i].first);
        }
        return ans;
    }
};