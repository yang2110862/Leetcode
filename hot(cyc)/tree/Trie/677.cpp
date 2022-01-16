#include "header.h"

class MapSum {
private:
    vector<MapSum*> child;
    bool isEnd;
    int value;
    int total(MapSum* root) {
        int res = root->value;
        for (auto node : root->child) {
            if (node != nullptr) res += total(node);
        }
        return res;
    }
public:
    /** Initialize your data structure here. */
    MapSum() : child(26), isEnd(false), value(0) {}
    
    void insert(string key, int val) {
        MapSum* node = this;
        for (char ch : key) {
            ch -= 'a';
            if (node->child[ch] == nullptr) node->child[ch] = new MapSum();
            node = node->child[ch];
        }
        node->isEnd = true;
        node->value = val;
    }
    
    int sum(string prefix) {
        MapSum* node = this;
        for (char ch : prefix) {
            node = node->child[ch -'a'];
            if (node == nullptr) return 0;
        }
        return total(node);
    }
};
