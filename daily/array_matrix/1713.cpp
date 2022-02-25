#include "header.h"

class Solution {
private:
    unordered_map<int, int> mp;
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        for (int i = 0; i < n; ++i) {
            mp[target[i]] = i;
        }
        vector<int> d;
        for (int x : arr) {
            if (mp.count(x)) {
                 auto it = lower_bound(d.begin(), d.end(), mp[x]);
                 if (it != d.end()) {
                     *it = mp[x];
                 } else {
                     d.push_back(mp[x]);
                 }
            }
        }
        return n - d.size();
    }
};