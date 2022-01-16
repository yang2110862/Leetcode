#include "header.h"
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hashTable;
        int mostFre = 0;
        for (auto x : nums) {
            mostFre = max(++hashTable[x], mostFre);
        }
        vector<vector<int>> buckets(mostFre + 1);
        for (auto x : hashTable) {
            buckets[x.second].push_back(x.first);
        }
        vector<int> ans;
        for (int i = mostFre; i >=0 && ans.size() < k; --i) {
            for (int num : buckets[i]) {
                if (ans.size() == k) break;
                ans.push_back(num);
            }
        }
        return ans;
    }
};