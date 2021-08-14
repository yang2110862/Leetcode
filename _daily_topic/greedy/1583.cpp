#include "header.h"
//统计不开心的朋友
class Solution {
private:
    unordered_map<int, unordered_map<int, int>> mp;
    unordered_map<int, int> pair_mp;
    void creat_mp(vector<vector<int>>& preferences) {
        int n = preferences.size();
        for (int i = 0; i < n; ++i) {
            int m = preferences[i].size();
            unordered_map<int, int> prior;
            for (int j = 0; j < m; ++j) {
                prior[preferences[i][j]] = j;
            }
            mp[i] = prior;
        }
    }
    void creat_pair(vector<vector<int>>& pairs) {
        for(auto& pair : pairs) {
            pair_mp[pair[0]] = pair[1];
            pair_mp[pair[1]] = pair[0];
        }
    }
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        creat_mp(preferences);
        creat_pair(pairs);
        int ans = 0;
        for (int x = 0; x < n; ++x) {
            int y = pair_mp[x];
            int y_prior = mp[x][y];
            for (int j = 0; j < y_prior; ++j) {
                int u = preferences[x][j];
                int v = pair_mp[u];
                if (mp[u][x] < mp[u][v]) {
                    ++ans;
                    break;
                }
            }
        }
        return ans;
    }
};