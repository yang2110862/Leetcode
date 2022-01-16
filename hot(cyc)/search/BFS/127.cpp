#include "header.h"

class Solution {
private:
    bool isConnect(const string& word1, const string& word2) {
        int x = word1.size();
        int y = word2.size();
        if (x != y) {
            return false;
        }
        int flag = 0;
        for (int i = 0; i < x; ++i) {
            if (flag > 1) {
                break;
            }
            if (word1[i] != word2[i]) {
                ++flag;
            }
        }
        if (flag < 2) {
            return true;
        } else {
            return false;
        }
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_map<string, int> mem;
        for (auto x : wordList) {
            mem[x] = 0;
        }
        q.push(beginWord);
        mem[q.front()] = 1;
        int ans = 0;
        //bfs
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto currWord = q.front();
                if (currWord == endWord) {
                    return ans + 1;
                }
                /*for (auto x : wordList) {        //不剪枝导致超时
                    if (!mem[x] && isConnect(x, currWord)) {
                        q.push(x);
                        mem[x] = 1;
                    }
                }*/
                auto it = wordList.begin();
                while (it != wordList.end()) {
                    if (!mem[*it] && isConnect(*it ,currWord)) {
                        q.push(*it);
                        mem[*it] = 1;
                        wordList.erase(it);       //剪枝
                    } else {
                        ++it;
                    }
                }
                q.pop();
            }
            ++ans;
        }
        return 0;
    }
};