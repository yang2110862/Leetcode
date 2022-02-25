#include "header.h"
//从相邻元素对还原数组
class Solution {
private:
    unordered_map<int, vector<int>> adj;
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        for (auto& pairs : adjacentPairs) {
            adj[pairs[0]].push_back(pairs[1]);
            adj[pairs[1]].push_back(pairs[0]);
        }
        int beg;
        for (auto num : adj) {
            if (num.second.size() == 1) {
                beg = num.first;
                break;
            }
        }
        vector<int> ans;
        ans.push_back(beg);
        int pre = beg;
        beg = adj[beg][0];
        ans.push_back(beg);
        if (adjacentPairs.size() == 1) return ans;
        int end = pre == adj[beg][0] ? adj[beg][1] : adj[beg][0];
        ans.push_back(end);
        pre = beg;
        while (adj[end].size() == 2) {
            beg = end;
            end = pre == adj[beg][0] ? adj[beg][1] : adj[beg][0];
            pre = beg;
            ans.push_back(end);
        }
        return ans;
    }
};
