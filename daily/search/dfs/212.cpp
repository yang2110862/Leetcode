#include "header.h"
//单词搜索 II dfs 超时
class Solution1 {
unordered_map<char, vector<pair<int, int>>> locs;
    bool dfs(string& target, int index, vector<vector<char>>& board, int m, int n, vector<vector<bool>>& visited) {
        if (board[m][n] != target[index]) return false;
        if (index == target.size() - 1) return true;
        visited[m][n] = true;
        vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < 4; ++i) {
            int new_m = m + dirs[i].first;
            int new_n = n + dirs[i].second;
            if (new_m >= 0 && new_m < board.size() && new_n >= 0 && new_n < board[0].size() && !visited[new_m][new_n]) {
                if (dfs(target, index + 1, board, new_m, new_n, visited)) {
                    return true;
                }
            }
        }
        visited[m][n] = false;
        return false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                locs[board[i][j]].emplace_back(i, j);
            }
        }
        vector<string> ans;
        for (auto& word : words) {
            for (auto& loc : locs[word[0]]) {
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                if (dfs(word, 0, board, loc.first, loc.second, visited)) {
                    ans.push_back(word);
                    break;
                }
            }
        }
        return ans;
    }
};

//trie