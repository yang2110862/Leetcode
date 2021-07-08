#include "header.h"

class Solution {
private:
    unordered_set<string> dead;
    unordered_set<string> visited;
    vector<string> getStatus(string& status) {
        vector<string> ans;
        for (int i = 0; i < 4; ++i) {
            char num = status[i];
            status[i] = (num == '9') ? '0' : num + 1;
            ans.push_back(status);
            status[i] = (num == '0') ? '9' : num - 1;
            ans.push_back(status);
            status[i] = num;
        }
        return ans;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
        for (auto& deadend : deadends) dead.insert(deadend);
        if (dead.count("0000")) return -1;
        queue<pair<string, int>> que;
        que.push(make_pair("0000", 0));
        
        while (!que.empty()) {
            auto [status, step] = que.front();
            que.pop();
            for (auto& s : getStatus(status)) {
                if (!dead.count(s) && !visited.count(s)) {
                    if (s == target) return step + 1;
                    que.push(make_pair(s, step + 1));
                    visited.insert(s);
                }
            }
        }
        return -1;
    }
};