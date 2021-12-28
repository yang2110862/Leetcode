#include "header.h"

class Trie {
private:
    vector<Trie*> child;
    bool isEnd;
    Trie* findPrefix(string prefix) {
        Trie* node = this;
        for (auto c : prefix) {
            int num = c - 'a';
            if (node->child[num] == nullptr) return nullptr;
            node = node->child[num];
        }
        return node;
    }
public:
    Trie() : child(26), isEnd(false){}
    
    void insert(string word) {
        Trie* node = this;
        for (auto c : word) {
            int num = c - 'a';
            if (node->child[num] == nullptr) {
                node->child[num] = new Trie();
            }
            node = node->child[num];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = findPrefix(word);
        return node && node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = findPrefix(prefix);
        return node;
    }
};
