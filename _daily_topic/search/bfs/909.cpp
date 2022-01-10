#include "header.h"
//朴素bfs
class Solution {
private:
    unordered_set<int> visited;
    vector<int> convert2dimTo1dim(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int len = m * n;
        vector<int> arr;
        int leftToRight = true;
        for (int i = m - 1; i >= 0; --i) {
            if (leftToRight) {
                leftToRight = false;
                for (int j = 0; j < n; ++j) {
                    arr.push_back(board[i][j]);
                }
            } else {
                leftToRight = true;
                for (int j = n - 1; j >= 0; --j) {
                    arr.push_back(board[i][j]);
                }
            }
        }
        return arr;
    }
    vector<int> canReach(int num, vector<int> arr) {
        int len = arr.size();
        vector<int> ret;
        for (int i = 1; i <= 6; ++i) {
            if ((num + i) <= len) {
                if (arr[num + i - 1] != -1) {
                    if (visited.count(arr[num + i - 1])) continue;
                    ret.push_back(arr[num + i - 1]);
                }  else{
                   if (visited.count(num + i)) continue;
                   ret.push_back(num + i);
                }
            }
        }
        return ret;
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int len = m * n;
        vector<int> arr(len);
        arr = convert2dimTo1dim(board);
        queue<int> que;
        que.push(1);
        visited.insert(1);
        int step = 0;
        while (!que.empty()) {
            int num = que.size();
            ++step;
            for (int i = 0; i < num; ++i) {
                int loc = que.front();
                que.pop();
                for (auto x : canReach(loc, arr)) {
                    if (x == len) return step;
                    que.push(x);
                    visited.insert(x);
                }
            }
        }
        return -1;
    }
};

//A*
struct AStar {
    
}
class Solution {
private:
    unordered_set<int> visited;
    vector<int> convert2dimTo1dim(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int len = m * n;
        vector<int> arr;
        int leftToRight = true;
        for (int i = m - 1; i >= 0; --i) {
            if (leftToRight) {
                leftToRight = false;
                for (int j = 0; j < n; ++j) {
                    arr.push_back(board[i][j]);
                }
            } else {
                leftToRight = true;
                for (int j = n - 1; j >= 0; --j) {
                    arr.push_back(board[i][j]);
                }
            }
        }
        return arr;
    }
    vector<int> canReach(int num, vector<int> arr) {
        int len = arr.size();
        vector<int> ret;
        for (int i = 1; i <= 6; ++i) {
            if ((num + i) <= len) {
                if (arr[num + i - 1] != -1) {
                    if (visited.count(arr[num + i - 1])) continue;
                    ret.push_back(arr[num + i - 1]);
                }  else{
                   if (visited.count(num + i)) continue;
                   ret.push_back(num + i);
                }
            }
        }
        return ret;
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int len = m * n;
        vector<int> arr(len);
        arr = convert2dimTo1dim(board);
        queue<int> que;
        que.push(1);
        visited.insert(1);
        int step = 0;
        while (!que.empty()) {
            int num = que.size();
            ++step;
            for (int i = 0; i < num; ++i) {
                int loc = que.front();
                que.pop();
                for (auto x : canReach(loc, arr)) {
                    if (x == len) return step;
                    que.push(x);
                    visited.insert(x);
                }
            }
        }
        return -1;
    }
};