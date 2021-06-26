#include "header.h"

class Solution {
private:
    vector<vector<int>> target{{1, 2, 3}, {4, 5, 0}};
    vector<vector<vector<int>>> getStauses(vector<vector<int>>& status) {
        int x, y;
        int m = status.size();
        int n = status[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (status[i][j] == 0) {
                    x = i;
                    y = j;
                }
            }
        }
        vector<vector<vector<int>>> ret;
        if (x == 0) {
            if (y == 0) {
                swap(status[x][y], status[x + 1][y]);
                ret.push_back(status);
                swap(status[x][y], status[x + 1][y]);

                swap(status[x][y], status[x][y + 1]);
                ret.push_back(status);
                swap(status[x][y], status[x][y + 1]);
            } else if (y == n - 1){
                swap(status[x][y], status[x + 1][y]);
                ret.push_back(status);
                swap(status[x][y], status[x + 1][y]);

                swap(status[x][y], status[x][y - 1]);
                ret.push_back(status);
                swap(status[x][y], status[x][y - 1]);
            } else {
                swap(status[x][y], status[x + 1][y]);
                ret.push_back(status);
                swap(status[x][y], status[x + 1][y]);

                swap(status[x][y], status[x][y + 1]);
                ret.push_back(status);
                swap(status[x][y], status[x][y + 1]);

                swap(status[x][y], status[x][y - 1]);
                ret.push_back(status);
                swap(status[x][y], status[x][y - 1]);
            }
        } else {
            if (y == 0) {
                swap(status[x][y], status[x - 1][y]);
                ret.push_back(status);
                swap(status[x][y], status[x - 1][y]);

                swap(status[x][y], status[x][y + 1]);
                ret.push_back(status);
                swap(status[x][y], status[x][y + 1]);
            } else if (y == n - 1){
                swap(status[x][y], status[x - 1][y]);
                ret.push_back(status);
                swap(status[x][y], status[x - 1][y]);

                swap(status[x][y], status[x][y - 1]);
                ret.push_back(status);
                swap(status[x][y], status[x][y - 1]);
            } else {
                swap(status[x][y], status[x - 1][y]);
                ret.push_back(status);
                swap(status[x][y], status[x - 1][y]);

                swap(status[x][y], status[x][y + 1]);
                ret.push_back(status);
                swap(status[x][y], status[x][y + 1]);

                swap(status[x][y], status[x][y - 1]);
                ret.push_back(status);
                swap(status[x][y], status[x][y - 1]);
            }
        }
        return ret;
    }
    bool isTarget(vector<vector<int>>& status) {
        for (int i = 0; i < target.size(); ++i) {
            for (int j = 0; j < target[0].size(); ++j) {
                if (target[i][j] != status[i][j]) return false;
            }
        }
        return true;
    }
    string toString(vector<vector<int>>& status) {
        string ret;
        for (int i = 0; i < status.size(); ++i) {
            for (int j = 0; j < status[0].size(); ++j) {
                ret += to_string(status[i][j]);
            }
        }
        return ret;
    }
    unordered_set<string> visited;
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        if (isTarget(board)) return 0;
        queue<pair<vector<vector<int>>, int>> que;
        que.push({board, 0});
        visited.insert(toString(board));
        while (!que.empty()) {
            int n = que.size();
            for (int i = 0; i < n; ++i) {
                auto curr = que.front();
                que.pop();
                for (auto status : getStauses(curr.first)) {
                    if (visited.count(toString(status))) continue;
                    if (isTarget(status)) {
                        return curr.second + 1;
                    } else {
                        que.push({status, curr.second + 1});
                    }
                    visited.insert(toString(status));
                }
            }
        }
        return -1;
    }
};
