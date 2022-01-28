#include "header.h"

//实现 Trie (前缀树)

class Trie {
private:
    vector<Trie*> children;
    bool isEnd;
public:
    Trie() {
        children.resize(26, nullptr);
        isEnd = false;
    }
    
    void insert(string word) {
        Trie* p = this;
        for (auto c : word) {
            if (p->children[c - 'a'] == nullptr) {
                p->children[c - 'a'] = new Trie;
            }
            p = p->children[c - 'a'];
        }
        p->isEnd = true;
    }
    
    bool search(string word) {
        Trie* p = this;
        for (auto c : word) {
            if (p->children[c - 'a'] == nullptr) return false;
            else p = p->children[c - 'a'];
        }
        if (p->isEnd == true) return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        Trie* p = this;
        for (auto c : prefix) {
            if (p->children[c - 'a'] == nullptr) return false;
            else p = p->children[c - 'a'];
        }
        return true;
    }
};

int main() {
    Trie* test = new Trie();
    test->insert("aa");
    test->insert("ab");
    cout << test->startsWith("ab");
}