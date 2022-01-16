#include "header.h"

class Solution {
private:
    int cnt;
    unordered_map<int, unordered_set<int>> mp;
    void creatMap(vector<vector<int>>& relation) {
        for (auto& arr : relation) {
            mp[arr[0]].insert(arr[1]);
        }
    }
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        creatMap(relation);
        int target = n - 1;
        queue<int> q;
        q.push(0);
        for (int i = 0; i < k; ++i) {
            int n = q.size();
            for (int j = 0; j < n; ++j) {
                int loc = q.front();
                q.pop();
                for (auto x : mp[loc]) {
                    q.push(x);
                }
            }
        }
        while (!q.empty()) {
            if (q.front() == target) cnt++;
            q.pop();
        }
        return cnt;
    }
};