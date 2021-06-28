#include "header.h"

//TL  把所有站点连起来
class Solution1 {
private:
    unordered_map<int, unordered_set<int>> mp;
    unordered_set<int> visited;
    void creat_set(vector<vector<int>>& routes) {
        for (auto& vec : routes) {
            for (auto beg : vec) {
                for (auto end : vec) {
                    mp[beg].insert(end);
                }
            }
        }
    }
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        creat_set(routes);
        if (source == target) return 0;
        queue<int> q;
        q.push(source);
        visited.insert(source);
        int step = 0;
        while (!q.empty()) {
            int n = q.size();
            ++step;
            for (int i = 0; i < n; ++i) {
                int loc = q.front();
                q.pop();
                for (auto x : mp[loc]) {
                    if (visited.count(x)) continue;
                    if (x == target) return step;
                    q.push(x);
                    visited.insert(x);
                }
            }
        }
        return -1;
    }
};

//只考虑线路 不遍历所有点   visited记录到过的线路
class Solution {
private:
    unordered_map<int, unordered_set<int>> mp;  //站点key能到哪些线路value
    unordered_set<int> visited;
    void creat_set(vector<vector<int>>& routes) {
        int n = routes.size();
        for (int i = 0; i < n; ++i) {
            for (auto x : routes[i]) {
                mp[x].insert(i);
            }
        }
    }
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        creat_set(routes);
        if (source == target) return 0;
        queue<int> q;
        q.push(source);
        int step = 0;
        while (!q.empty()) {
            int n = q.size();
            ++step;
            for (int i = 0; i < n; ++i) {
                int loc = q.front();
                q.pop();
                for (auto x : mp[loc]) {
                    if (visited.count(x)) continue;
                    int m = routes[x].size();
                    for (int j = 0; j < m; ++j) {
                        if (routes[x][j] == target) return step;
                        q.push(routes[x][j]);
                    }
                    visited.insert(x);
                }
            }
        }
        return -1;
    }
};