#include "header.h"

//472.连接词


//暴力法超时
class Solution {
private:
    unordered_map<string, bool> mp;
    void creat_hash(const vector<string>& words) {
        for (auto& word : words) {
            mp[word] = true;
        }
    }
    bool traverse(const string& words, int index, int cnt) {
        int n = words.size();
        if (index == n && cnt > 1) return true;
        for (int i = index;i < n; ++i) {
            string ele = words.substr(index, (i - index) + 1);
            if (mp[ele]) {
                if (traverse(words, i + 1, cnt + 1)) return true;
            }
        }
        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        creat_hash(words);
        int n = words.size();
        vector<string> ans;
        for (int i = 0; i < n; ++i) {
            if (traverse(words[i], 0, 0)) ans.push_back(words[i]);
        }
        return ans;
    }
};

//字典树
class Trie {
public:
    vector<Trie*> child;
    bool isEnd;
public:
    Trie() {
        child = vector<Trie*>(26);
        isEnd = false;
    }
};
class Solution {
private:
    Trie *trie = new Trie();
    bool dfs(const string& word, int start) {
        if (start == word.size()) return true;
        Trie* node = trie;
        for (int i = start; i < word.size(); ++i) {
            int num = word[i] - 'a';
            if (node->child[num] == nullptr) {
                return false;
            }
            if (node->child[num]->isEnd) {
                if (dfs(word, i+1)) {
                    return true;
                }
            }
            node = node->child[num];
        }
        return false;
    }
    void insert(const string& word) {
        Trie* node = trie;
        for (int i = 0; i < word.size(); ++i) {
            int num = word[i] - 'a';
            if (node->child[num] == nullptr) {
                node->child[num] = new Trie();
            }
            node = node->child[num];
        }
        node->isEnd = true;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        int n = words.size();
        vector<string> ans;
        for (int i = 0; i < n; ++i) {
            if (words[i].size() == 0) continue;
            if (dfs(words[i], 0)) {
                ans.push_back(words[i]);
            } else {
                insert(words[i]);
            }
        }
        return ans;
    }
};