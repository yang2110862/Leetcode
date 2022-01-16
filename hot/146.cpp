#include "header.h"

//LRU 缓存

class LRUCache {
private:
    struct DLinkedNode {
        int key, value;
        DLinkedNode* pre, *next;
        DLinkedNode() : key(0), value(0), pre(nullptr), next(nullptr) {}
        DLinkedNode(int k, int v) : key(k), value(v), pre(nullptr), next(nullptr) {}
    };
    unordered_map<int, DLinkedNode*> mp;
    DLinkedNode* head;
    DLinkedNode* tail;
    int capacity;
    int size;
    void addToHead(DLinkedNode* node) {
        head->next->pre = node;
        node->next = head->next;
        node->pre = head;
        head->next = node;
    }
    void delNode(DLinkedNode* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    void moveToHead(DLinkedNode* node) {
        delNode(node);
        addToHead(node);
    }
public:
    LRUCache(int capacity) {
        head = new DLinkedNode;
        tail = new DLinkedNode;
        head->next = tail;
        tail->pre = head;
        this->capacity = capacity;
        size = 0;
    }
    
    int get(int key) {
        if (mp.count(key)) {
            moveToHead(mp[key]);
            return mp[key]->value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (!mp.count(key)) {
            DLinkedNode* node = new DLinkedNode(key, value);
            addToHead(node);
            mp[node->key] = node;
            ++size;
            if (size > capacity) {
                DLinkedNode* node = tail->pre;
                delNode(node);
                mp.erase(node->key);
                delete node;
                --size;
            }
        } else {
            DLinkedNode* node = mp[key];
            moveToHead(node);
            node->value = value;
        }
    }
};

int main() {
    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // 缓存是 {1=1}
    lRUCache->put(2, 2); // 缓存是 {1=1, 2=2}
    lRUCache->get(1);    // 返回 1
    lRUCache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    lRUCache->get(2);    // 返回 -1 (未找到)
    // lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    // lRUCache.get(1);    // 返回 -1 (未找到)
    // lRUCache.get(3);    // 返回 3
    // lRUCache.get(4);    // 返回 4
}