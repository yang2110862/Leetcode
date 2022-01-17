#include "header.h"

class LRUCache {
public:
struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};
private:
    unordered_map<int, DLinkedNode*> mp;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;
    void removeNode(DLinkedNode* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next = node;
        node->next->prev = node;
    }
    void moveTohead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }
public:
    LRUCache(int capacity) {
        head = new DLinkedNode;
        tail = new DLinkedNode;
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
        this->size = 0;
    }
    
    int get(int key) {
        if (!mp.count(key)) return -1;
        moveTohead(mp[key]);
        return mp[key]->value;
    }
    
    void put(int key, int value) {
        if (!mp.count(key)) {
            DLinkedNode* node = new DLinkedNode(key, value);
            mp[key] = node;
            addToHead(node);
            ++size;
            if (size > capacity) { 
                mp.erase(tail->prev->key);
                removeNode(tail->prev);  
                --size;
            } 
        } else {
            DLinkedNode* node = mp[key];
            node->value = value;
            moveTohead(node);
        }
    }
};
